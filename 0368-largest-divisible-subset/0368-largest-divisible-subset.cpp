class Solution {
private: 
    vector<int> solve(int n , vector<int> &arr){
        vector<int> dp(n,1),idx(n,0);
        int maxi=1,maxId=0;
        for(int i=0;i<n;i++)
        idx[i]=i;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j]==0 && 1+dp[j]>dp[i]){
                    idx[i]=j;
                    dp[i]=1+dp[j];
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                maxId=i;
            }
        }
        vector<int> ans;
        while(true){
            if(maxId==idx[maxId]){
                ans.push_back(arr[maxId]);
                break;
            }
            ans.push_back(arr[maxId]);
            maxId=idx[maxId];
        }
        return ans;
    }
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return solve(nums.size(),nums);
    }
};