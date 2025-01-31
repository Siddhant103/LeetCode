class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        if(row == 0){
            return 0;
        }
        
        int col = grid[0].size();
        int max_area = 0, islandId = 2;
        unordered_map<int, int> m;
        vector<vector<int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j] == 1){
                    int area = formatGrid(grid, i, j, row, col, islandId);
                    max_area = max(area, max_area);
                    m[islandId] = area;
                    islandId++;
                }
            }
        }
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j] == 0){
                    unordered_set<int> s;
                    for(auto dir: dirs){
                        int x = dir[0] + i, y = dir[1] + j;
                        if(x > -1 && y > -1 && x < row && y < col && grid[x][y] != 0){
                            s.insert(grid[x][y]);
                        }
                    }
                    
                    int sum = 1;
                    for(auto item: s){
                        int val = m[item];
                        sum += val;
                    }
                    
                    max_area = max(max_area, sum);
                }
                
            }
        }
        
        return max_area;
    }
    
    int formatGrid(vector<vector<int>>& grid, int i, int j, int n, int m, int islandId){
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != 1){
            return 0;
        }
        
        grid[i][j] = islandId;
        
        int area = 1 + formatGrid(grid, i + 1, j, n, m, islandId) + formatGrid(grid, i - 1, j, n, m, islandId)
                     + formatGrid(grid, i, j + 1, n, m, islandId) + formatGrid(grid, i, j - 1, n, m, islandId);
        
        return area;
    }
};