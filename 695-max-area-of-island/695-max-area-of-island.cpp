class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 0)
            return 0;
        
        int m = grid[0].size();
        int maxArea = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int curr = 0;
                if(grid[i][j] == 1){
                    curr = calculateArea(grid, i, j, n, m);
                }
                maxArea = max(maxArea, curr);
            }
        }
        
        return maxArea;
    }
    
    int calculateArea(vector<vector<int>>& grid, int i, int j, int n, int m){
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0){
            return 0;
        }
        
        grid[i][j] = 0;
        
        int area = 1 + calculateArea(grid, i + 1, j, n, m) + calculateArea(grid, i - 1, j, n, m) +
                    calculateArea(grid, i, j + 1, n, m) + calculateArea(grid, i, j - 1, n, m);
        
        return area;
    }
};