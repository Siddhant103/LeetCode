class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        int result = 0;
        vector<int> row(n, 0), col(n, 0);

        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                row[i] = max(row[i], grid[i][j]);
                col[j] = max(col[j], grid[i][j]);
            }
        }

        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                result += min(row[i], col[j]) - grid[i][j];
            }
        }

        return result;
    }
};