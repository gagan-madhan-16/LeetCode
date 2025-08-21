class Solution {
public:
    int solve(int idx,vector<int> &nums,vector<int> &dp){
        if(idx==nums.size()-1)
        return 0;

        if(dp[idx]==-1){
            int canJump=nums[idx];
            int curr=INT_MAX-2;
            for(int i=1;i<=canJump;i++){
                if(idx+i<nums.size())
                curr=min(curr,1+solve(idx+i,nums,dp));
            }
            dp[idx]=curr;
        }

        return dp[idx];
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return solve(0,nums,dp);
    }
};