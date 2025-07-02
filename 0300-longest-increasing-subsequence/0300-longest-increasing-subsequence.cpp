class Solution {
private:
    int n;
    int memoisation(int prev , int idx , vector<vector<int>> &dp , vector<int> &arr){
        if(idx==n)
        return 0;

        if(prev == -1 || dp[idx][prev+1]==-1){
            int len = memoisation(prev , idx+1 , dp , arr);
            if(prev==-1 || arr[prev] < arr[idx]){
                len = max(len  , 1+memoisation(idx , idx+1 , dp , arr));
            }

            dp[idx][prev+1] = len;
        }

        return dp[idx][prev+1];
    }
    int tabulation(int n , vector<int> &arr){
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int idx = n-1; idx>=0 ; idx--){
            for(int prev = idx-1 ; prev >= -1 ; prev--){
                int len = dp[idx+1][prev+1];
                if(prev==-1 || arr[prev] < arr[idx]){
                    len = max(len  , 1+dp[idx+1][idx+1]);
                }
                dp[idx][prev+1] = len;
            }
        }

        return dp[0][0];
    }
    int SpaceOptimiztionTabulation(int n , vector<int> &arr){
        vector<int> next(n+1,0) , curr(n+1,0);
        for(int idx = n-1; idx>=0 ; idx--){
            for(int prev = idx-1 ; prev >= -1 ; prev--){
                int len = next[prev+1];
                if(prev==-1 || arr[prev] < arr[idx]){
                    len = max(len  , 1+next[idx+1]);
                }
                curr[prev+1] = len;
            }
            next = curr;
        }

        return curr[0];
    }
    // {10,9,2,5,3,7,101,18}
    int printingLis(int n , vector<int> &arr){
        vector<int> dp(n,1),idx(n,0);
        int maxi=1,maxId=0;
        for(int i=0;i<n;i++)
        idx[i]=i;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[i]>arr[j] && 1+dp[j]>dp[i]){
                    idx[i]=j;
                    dp[i]=1+dp[j];
                    maxi=max(maxi,dp[i]);
                    maxId=i;
                }
            }
        }
        while(true){
            cout<<arr[maxId]<<' ';
            maxId=idx[maxId];
            if(maxId==idx[maxId]){
                cout<<arr[maxId];
                break;
            }
        }
        return maxi;

    }
    int  moreOptimization(int n , vector<int> &arr){
        vector<int> ans(n,1);
        int maxi=0;
        for(int i=1;i<n;i++){
            auto it = lower_bound(arr.begin(), arr.begin()+i, arr[i]);
            if(it!=arr.begin())
            ans[i] = 1+ans[it-1-arr.begin()];
            maxi=max(maxi,ans[i]);
        }
        return maxi;
    }
public:
    int lengthOfLIS(vector<int>& arr) {
        n = arr.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        // int ans = memoisation(-1,0,dp,arr);
        // int ans = tabulation(n,arr);
        // int ans = SpaceOptimiztionTabulation(n,arr);
        int ans = printingLis(n,arr);
        // int ans = moreOptimization(n,arr);

        return ans;
       
    }
};