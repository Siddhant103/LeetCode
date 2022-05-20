class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.size()==0)
            return 0;
        if(obstacleGrid[0][0]==1)
            return 0;
        vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size()));
        cout<<obstacleGrid.size()<<" "<<obstacleGrid[0].size()<<endl;
        dp[0][0]=1;
        
        for(int i=1;i<obstacleGrid.size();i++){
            if(obstacleGrid[i][0]!=1)
                dp[i][0] = dp[i-1][0];
            else
                dp[i][0] = 0;
        }
        cout<<endl;
        for(int i=1;i<obstacleGrid[0].size();i++){
            cout<<i<<" ";
            
            if(obstacleGrid[0][i]!=1)
                dp[0][i] = dp[0][i-1];
            else
                dp[0][i] = 0;
        }
        //exit(0);
        for(int i=1;i<obstacleGrid.size();i++){
            for(int j=1;j<obstacleGrid[i].size();j++){
                if(obstacleGrid[i][j]==0){
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                } else{
                    dp[i][j] = 0;
                }
            }
        }
        
        return dp[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};