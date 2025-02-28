class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int n = s1.size(), m = s2.size();
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
	
        int i=n, j=m;
        string result = "";
        int len = dp[n][m];
        for (int k=0;k<n+m-len;k++) {
            result += "$";
        }
        int index = n+m-len - 1;
        while (i > 0 && j > 0) {
            if (s1[i - 1] == s2[j - 1]) {
                result[index] = s1[i - 1];
                index--;
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                result[index] = s1[i - 1];
                index--;
                i--;
            } else {
                result[index] = s2[j - 1];
                index--;
                j--;
            }
        }

        while (i > 0) {
            result[index] = s1[i - 1];
            index--;
            i--;
        }
        while (j > 0) {
            result[index] = s2[j - 1];
            index--;
            j--;
        }
        return result;
    }
};