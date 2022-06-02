class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> ans(col, vector<int>(row));
        
        int i=0;
        int j=0;
        
        for(i=0;i<row;i++){
            for(j=0;j<col;j++){
                ans[j][i] = matrix[i][j];
            }
        }
        
        return ans;
        
    }
};