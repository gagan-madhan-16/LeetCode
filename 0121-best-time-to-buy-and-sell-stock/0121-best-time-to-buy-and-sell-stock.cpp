class Solution {
public:
    int maxProfit(vector<int>& v) {
        int n = v.size();
        vector<int> maxi(v.size());
        maxi[n-1]=v[n-1];
        for(int i=n-2;i>=0;i--)
        {
            maxi[i]=max(maxi[i+1],v[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        ans=max(ans,maxi[i]-v[i]);

        return ans;

    }
};