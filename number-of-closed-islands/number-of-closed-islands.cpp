class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        if(grid.size() == 0){
            return 0;
        }
        
        int islandCount = 0, rows = grid.size(), cols = grid[0].size();
        
        for(int i=1;i<rows-1;i++){
            for(int j=1;j<cols-1;j++){
                if(grid[i][j] == 0){
                    islandCount += (dfs(grid, i, j, rows, cols) ? 1 : 0);
                }
            }
        }
        
        return islandCount;
    }
    
    bool dfs(vector<vector<int>>& grid, int i, int j, int rows, int cols){
        if(grid[i][j] == -1 || grid[i][j] == 1)   
            return true;
        
        if( i == 0 || j == 0 || i == rows - 1 || j == cols - 1){
            return false;
        }
        
        grid[i][j] = -1;
        bool left = dfs(grid, i - 1, j, rows, cols);
        bool right = dfs(grid, i + 1, j, rows, cols);
        bool down = dfs(grid, i, j - 1, rows, cols);
        bool up = dfs(grid, i, j + 1, rows, cols);
        
        return left && right && up && down;
        
    }
};