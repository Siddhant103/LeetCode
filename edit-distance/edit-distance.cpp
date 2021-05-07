class Solution {
public:
    int minDistance(string word1, string word2) {
        int row = word1.size();
        int col = word2.size();
        
        vector<vector<int>> dp(row+1, vector<int>(col+1,0));

        dp[0][0] = 0;
        for(int i=1;i<=row;i++){
            dp[i][0] = dp[i-1][0] + 1;
        }
        //exit(0);
        for(int i=1;i<=col;i++){
            dp[0][i] = dp[0][i-1] + 1;
        }
        
        //exit(0);
        for(int i=1;i<=row;i++){
            for(int j=1;j<=col;j++){
                if(word1[i-1]!=word2[j-1])
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                else
                    dp[i][j] = dp[i-1][j-1];
            }
        }
        
        return dp[row][col];
    }
};