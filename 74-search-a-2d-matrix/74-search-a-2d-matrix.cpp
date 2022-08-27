class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int row = 0, col = m - 1;
        
        while (row < n && col > -1) {
            int num = matrix[row][col];
            if (num == target) {
                return true;
            } else if (num < target) {
                row = row + 1;
            } else {
                col = col - 1;
            }
        }
        
        return false;
    }
};