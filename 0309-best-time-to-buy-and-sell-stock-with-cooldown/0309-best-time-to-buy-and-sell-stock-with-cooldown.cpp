class Solution {
private:
    int n;
    int solve(int idx , bool buy , vector<vector<int>> &dp , vector<int> &prices){
        if(idx >= n)
        return 0;

        if(dp[idx][buy]==-1){
            if(buy){
                dp[idx][buy] = max(-prices[idx]+solve(idx+1,!buy,dp,prices) , solve(idx+1,buy,dp,prices));
            }
            else
            dp[idx][buy] = max(prices[idx]+solve(idx+2,!buy,dp,prices) , solve(idx+1,buy,dp,prices));
        }

        return dp[idx][buy];
    }
public:
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        // vector<vector<int>> dp(n+2,vector<int>(2,0));
        vector<int> next(2,0) , curr(2,0);
        int next2=0;
        // return solve(0,1,dp,prices);

        for(int idx=n-1;idx>=0;idx--){
            for(int buy=0;buy<2;buy++){
                if(buy)
                curr[buy] = max(-prices[idx]+next[!buy] , next[buy]);
                else
                curr[buy] = max(prices[idx]+next2 , next[buy]);
            }
            next2=next[1];
            next=curr;
        }

        return curr[1];
    }
};