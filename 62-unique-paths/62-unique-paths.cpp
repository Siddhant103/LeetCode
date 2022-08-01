class Solution {
public:
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp(m, vector<int>(n,1));
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }
        
        return dp[m-1][n-1];
        
    }
    
    /*int getUniquePaths(int i, int j, int m, int n){//This will give TLE for bigger inputs
        if(i==m && j==n){
            return 1;
        }
        
        if(i>m || j>n)
            return 0;
        
        return getUniquePaths(i+1, j, m, n) + getUniquePaths(i, j+1, m, n);
    }*/
};