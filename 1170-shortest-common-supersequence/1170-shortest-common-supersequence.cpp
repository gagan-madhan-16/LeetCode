class Solution {
public:
    string shortestCommonSupersequence(string a, string b) {
        int n = a.size(), m = b.size();
    
    vector<vector<int>> dp(n+1, vector<int>(m+1));

    for (int j = 0; j <= m; j++)
        dp[0][j] = 0;
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i-1] == b[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    string S = "";
    int i = n, j = m;

    while (i > 0 || j > 0) {
        if (i == 0) {
            S = S + b[j-1];
            j--;
        }
        else if (j == 0) {
            S = S + a[i-1];
            i--;
        }
        else if (a[i-1] == b[j-1]) {
            S = S + a[i-1];
            i--;
            j--;
        }
       else if (dp[i-1][j] > dp[i][j-1]) {
            S = S + a[i-1];
            i--;
        } else {
            S = S + b[j-1];
            j--;
        }
    }

    reverse(S.begin(), S.end());

    return S;

    }
};