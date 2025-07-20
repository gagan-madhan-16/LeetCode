class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},1});
                    ans[i][j]=1;
                }
            }
        }

        while(!q.empty()){
            int i=q.front().first.first,j=q.front().first.second,t=q.front().second;
            q.pop();

            if(i>0 && mat[i-1][j]==1 && !ans[i-1][j]){
                q.push({{i-1,j},t+1});
                ans[i-1][j]=t+1;
            }

            if(j>0 && mat[i][j-1]==1 && !ans[i][j-1]){
                q.push({{i,j-1},t+1});
                ans[i][j-1]=t+1;
            }

            if(i<n-1 && mat[i+1][j]==1 && !ans[i+1][j]){
                q.push({{i+1,j},t+1});
                ans[i+1][j]=t+1;
            }

            if(j<m-1 && mat[i][j+1]==1 && !ans[i][j+1]){
                q.push({{i,j+1},t+1});
                ans[i][j+1]=t+1;
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j]-=1;
            }
        }

        return ans;
    }
};