class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        
        vector<vector<int>> ans;
        ans.push_back({rStart, cStart});
        int topRow = rStart - 1;
        int bottomRow = rStart + 1;
        int leftCol = cStart - 1;
        int rightCol = cStart + 1;
        
        while (topRow != -1 || bottomRow != rows || leftCol != -1 || rightCol != cols) { 
            if (rightCol != cols) {
                for(int i = topRow+1; i < bottomRow;i++) 
                    ans.push_back({i, rightCol});
                rightCol++;
            }
            if (bottomRow != rows) {
                for(int j = rightCol-1; j > leftCol; j--) 
                    ans.push_back({bottomRow, j});
                bottomRow++;
            }
            
            if (leftCol != -1) {
                for (int i = bottomRow-1; i > topRow; i--) 
                    ans.push_back({i, leftCol});
                leftCol--;
            }
            
            if (topRow != -1) {
                for (int j = leftCol+1; j < rightCol; j++) 
                    ans.push_back({topRow, j});
                topRow--;
            }  
        }
        
        return ans;
    }
};