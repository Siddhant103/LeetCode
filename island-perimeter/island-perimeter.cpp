class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 0){
            return 0;
        }
        
        int m = grid[0].size();
        int perimeter = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    perimeter += 4;
                    if(i > 0 && grid[i - 1][j] == 1){
                        perimeter -= 2;
                    }
                    if(j > 0 && grid[i][j - 1] == 1){
                        perimeter -= 2;
                    }
                }
            }
        }
        
        return perimeter;
    }
};