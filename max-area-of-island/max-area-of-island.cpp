class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if(n == 0){
            return 0;
        }
        
        int m = grid[0].size();
        int max_area = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    int area = getAreaOfIsland(grid, i, j, n, m);
                    max_area = max(max_area, area);
                }
            }
        }
        
        return max_area;
    }
    
    int getAreaOfIsland(vector<vector<int>>& grid, int i, int j, int n, int m){
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0){
            return 0;
        }
        
        grid[i][j] = 0;
        
        int area = 1 + getAreaOfIsland(grid, i + 1, j, n, m) +
            getAreaOfIsland(grid, i - 1, j, n, m) +
            getAreaOfIsland(grid, i, j + 1, n, m) +
            getAreaOfIsland(grid, i, j - 1, n, m);
        
        return area;
    }
};