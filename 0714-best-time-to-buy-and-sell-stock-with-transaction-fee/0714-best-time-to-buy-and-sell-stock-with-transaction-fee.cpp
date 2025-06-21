class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<int> next(2,0),curr(2,0);
        for(int idx=n-1;idx>=0;idx--){
            for(int buy=0;buy<2;buy++){
                if(buy)
                curr[buy] = max(-prices[idx]+next[!buy],next[buy]);
                else
                curr[buy] = max(prices[idx]+next[!buy]-fee,next[buy]);
            }
            next=curr;
        }
        return curr[1];
    }
};