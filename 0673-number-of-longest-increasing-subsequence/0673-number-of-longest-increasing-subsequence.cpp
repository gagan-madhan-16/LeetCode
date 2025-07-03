class Solution {
private:
    int solve(vector<int> &arr , int n){
        vector<int> ct(n,0),dp(n,1);
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[i]>arr[j] && 1+dp[j]>dp[i]){
                    dp[i]=1+dp[j];
                }
            }
            maxi=max(maxi,dp[i]);
            if(dp[i]==1){
                ct[i]=1;
                continue;
            }
            for(int j=0;j<i;j++){
                if(arr[i]>arr[j] && 1+dp[j]==dp[i]){
                    ct[i]+=ct[j];
                }
            }
        }
        cout<<endl;
        int ans=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxi)
            ans+=ct[i];
        }
        return ans;
    }
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        return solve(nums,n);
    }
};