class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<int> x(n + 1, 1);
        vector<int> y(m + 1, 1);
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if (!matrix[i][j]) {
                    x[i] = 0;
                    y[j] = 0;
                }
            }
        }
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if (x[i] == 0 || y[j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};