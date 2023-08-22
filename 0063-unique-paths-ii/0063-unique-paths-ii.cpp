class Solution {
public:
    int countPaths(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if(i<0 || j<0 || grid[i][j]==1) return 0;
        if(i==0 && j==0) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int up=countPaths(i-1,j,grid,dp);
        int left=countPaths(i,j-1,grid,dp);
        
        return dp[i][j]=up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return countPaths(n - 1, m - 1, obstacleGrid, dp);


    }
};