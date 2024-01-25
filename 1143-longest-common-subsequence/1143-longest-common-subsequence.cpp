class Solution {
public:
    int findMatches(string s1, string s2, int n, int m, vector<vector<int>>& dp) {
        if (n == 0 || m == 0) {
            return 0;
        }

        if (dp[n][m] != -1) {
            return dp[n][m];
        }
        if (s1[n - 1] == s2[m - 1]) {
            return dp[n][m] = 1 + findMatches(s1, s2, n - 1, m - 1, dp);
        } else {
            return dp[n][m] = max(findMatches(s1, s2, n, m - 1, dp),findMatches(s1, s2, n - 1, m, dp));
        }
    }
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        //vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        // return findMatches(s1, s2, n, m, dp);

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i=0;i<=m;i++) {
            dp[0][i] = 0;
        }
        for (int i=0;i<=n;i++) {
            dp[i][0] = 0;
        }

        for (int i=1;i<=n;i++) {
            for (int j=1;j<=m;j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n][m];
    }
};