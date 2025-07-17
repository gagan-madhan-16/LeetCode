class Solution {
private:
    void bfs(int i , vector<vector<int>> &adj , vector<int> &v){
        if(v[i]==1)
        return;

        queue<int> q;
        q.push(i);
        v[i]=1;
        while(!q.empty()){
            int  front = q.front();
            q.pop();

            for(auto ele : adj[front]){
                if(!v[ele]){
                    v[ele]=1;
                    q.push(ele);
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        vector<vector<int>> adj(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (M[i][j] == 1 && i != j)
                    adj[i].push_back(j);
            }
        }

        vector<int> v(n,0);
        int ct=0;
        for(int i=0;i<n;i++){
            if(!v[i]){
                bfs(i,adj,v);
                ct++;
            }
        }

        return ct;
    }
};