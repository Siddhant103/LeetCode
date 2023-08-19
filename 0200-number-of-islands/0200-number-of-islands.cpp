class Solution {
public:
    void sink(vector<vector<char>>& arr, int i, int j, int n, int m) {
    if (i < 0 || j < 0 || i >= n || j >= m || arr[i][j] == '0') {
        return;
    }

    arr[i][j] = '0';
    sink(arr, i + 1, j, n, m); //bottom
    sink(arr, i, j + 1, n, m); //right
    sink(arr, i, j - 1, n, m); //left
    sink(arr, i - 1, j, n, m); //top
    // sink(arr, i + 1, j + 1, n, m);
    // sink(arr, i - 1, j + 1, n, m);
    // sink(arr, i + 1, j - 1, n, m);
    // sink(arr, i + 1, j - 1, n, m);
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int n = grid.size(), m = grid[0].size();

        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                if (grid[i][j] == '1') {
                    count++;
                    sink(grid, i, j, n, m);
                }
            }
        }

        return count;
    }
};