class Solution {
public:
    int strangePrinter(string s) {
        int n = s.length();
        int dp[n][n];
        for(int i=0;i<n;i++) dp[i][i] = 1;
        
        for(int len=2; len<=n; len++) {
            for(int i=0;i<n-len+1;i++) {
                int j = i+len-1;
                dp[i][j] = INT_MAX;
                for(int r=i+1;r<=j;r++)
                    dp[i][j] = min(dp[i][j], dp[i][r-1] + dp[r][j] - ((s[i] == s[j]) ? 1 : 0));
            }
        }
        return dp[0][n-1];
    }
};