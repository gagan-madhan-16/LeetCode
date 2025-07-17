class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        
        int n=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==2){
                    q.push({n,0});
                    grid[i][j]=n;
                    n++;
                }
                else if(grid[i][j]==1){
                    grid[i][j]=n;
                    n++;
                }
                else
                grid[i][j]=-1;

                cout<<grid[i][j]<<' ';
            }
            cout<<endl;
        }
        vector<vector<int>> adj(n+1);
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==-1)
                continue;
                else{
                    if(i-1>=0 && grid[i-1][j]!=-1){
                        adj[grid[i][j]].push_back(grid[i-1][j]);
                        adj[grid[i-1][j]].push_back(grid[i][j]);                        
                    }
                    if(j-1>=0 && grid[i][j-1]!=-1){
                        adj[grid[i][j]].push_back(grid[i][j-1]);
                        adj[grid[i][j-1]].push_back(grid[i][j]);                        
                    }
                    if(i+1<grid.size() && grid[i+1][j]!=-1){
                        adj[grid[i][j]].push_back(grid[i+1][j]);
                        adj[grid[i+1][j]].push_back(grid[i][j]);
                    }
                    if(j+1<grid[i].size() && grid[i][j+1]!=-1){
                        adj[grid[i][j]].push_back(grid[i][j+1]);
                        adj[grid[i][j+1]].push_back(grid[i][j]);
                    }
                }
            }
        }

        queue<pair<int, int>> q_copy = q;
        vector<int> v(n,0);

        while (!q_copy.empty()) {
            auto it = q_copy.front();
            q_copy.pop();
            v[it.first] = 1;
        }

        int ans=0;

        while(!q.empty()){
            int node,ct;
            node=q.front().first;
            ct=q.front().second;
            q.pop();

            for(auto ele : adj[node]){
                if(!v[ele]){
                    q.push({ele,ct+1});
                    v[ele]=1;
                }
            }

            ans=max(ans,ct);
        }

        for(int i=0;i<n;i++){
            if(v[i]==0)
            ans=-1;
        }

        return ans;
    }
};