class Solution {
private:
    int solve(int i ,int j , string &s , string &t , vector<vector<int>> &dp){
        if(i>=s.size() || j>=t.size())
        return 0;

        if(j==t.size()-1){
            return (s[i]==t[j]) + solve(i+1,j,s,t,dp) + solve(i,j+1,s,t,dp);
        }

        if(dp[i][j]==-1){
            if(s[i]==t[j])
            return solve(i+1,j+1,s,t,dp) + solve(i+1,j,s,t,dp);
            else
            return solve(i+1,j,s,t,dp);
        }

        return dp[i][j];
    }
public:
    int numDistinct(string s, string t) {
        int n = s.size() , m = t.size();
        vector<vector<unsigned long long>> dp(s.size()+1,vector<unsigned long long>(t.size()+1,0));
        // return solve(0,0,s,t,dp);
        for(int i=n-1;i>=0;i--){
            dp[i][m-1] = (s[i]==t[m-1]) + dp[i+1][m-1];
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                if(s[i]==t[j])
                dp[i][j]=dp[i+1][j]+dp[i+1][j+1];
                else
                dp[i][j]=dp[i+1][j];
            }
        }

        return dp[0][0];
    }
};