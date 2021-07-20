class Solution {
    vector<vector<int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if(row == 0)
            return 0;
        
        int col = matrix[0].size();
        
        vector<vector<int>> cache(row, vector<int>(col, 0));
        int longestPath = 0;
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                int longest = LIPM(matrix, i, j, row, col, cache);
                longestPath = max(longestPath, longest);
            }
        }
        
        return longestPath;
    }
    
    int LIPM(vector<vector<int>>& matrix, int i, int j, int row, int col, vector<vector<int>>& cache){
        if(cache[i][j] > 0){
            return cache[i][j];
        }
        
        int maxVal = 0;
        
        for(auto dir: dirs){
            int x = dir[0] + i, y = dir[1] + j;
            if(x > -1 && y > -1 && x < row && y < col && matrix[x][y] > matrix[i][j]){
                int longest = LIPM(matrix, x, y, row, col, cache);
                maxVal = max(maxVal, longest);
            }
        }
        
        cache[i][j] = maxVal + 1;
        return cache[i][j];
    }
};