class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 0){
            return 0;
        }
        int m = grid[0].size();
        int max_gold = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] > 0){
                    vector<vector<bool>> visited(n, vector<bool>(m, false));
                    int gold = findMaxGold(grid, i, j, n, m, visited);
                    max_gold = max(gold, max_gold);
                }
            }
        }
        
        return max_gold;
    }
    
    int findMaxGold(vector<vector<int>>& grid, int i, int j, int n, int m, vector<vector<bool>>& visited){
        if(i < 0 || j < 0 || i >= n || j >= m || visited[i][j] == true || grid[i][j] == 0){
            return 0;
        }
        
        visited[i][j] = true;
        int max_gold = grid[i][j] + max(
            findMaxGold(grid, i + 1, j, n, m, visited),
            max(findMaxGold(grid, i - 1, j, n, m, visited),
               max(findMaxGold(grid, i, j + 1, n, m, visited), findMaxGold(grid, i, j - 1, n, m, visited)))
        );
        visited[i][j] = false;
        
        return max_gold;
    }
};