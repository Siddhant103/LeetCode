class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if (!n) {
            return 0;
        }
        int m = grid[0].size();
        int count = 0;
        
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                if (grid[i][j] == '1') {
                    count++;
                    sinkIsland(grid, i, j, n, m);
                }
            }
        }
        
        return count;
    }
    
    void sinkIsland(vector<vector<char>> &grid, int i, int j, int n, int m) {
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == '0') {
            return ;
        }
        
        grid[i][j] = '0';
        sinkIsland(grid, i + 1, j, n, m);
        sinkIsland(grid, i - 1, j, n, m);
        sinkIsland(grid, i, j + 1, n, m);
        sinkIsland(grid, i, j - 1, n, m);
    }
};