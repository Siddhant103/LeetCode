class Solution {
public:
    int countPaths(int i, int j, int n, int m, vector<vector<int>>& dp) {
        if (i >= n || j >= m) {
            return 0;
        }
        if (i == n - 1 && j == m - 1) {
            return 1;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int down = countPaths(i + 1, j, n, m, dp);
        int right = countPaths(i, j + 1, n, m, dp);

        return dp[i][j] = down + right;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return countPaths(0, 0, n, m, dp);
    }
};