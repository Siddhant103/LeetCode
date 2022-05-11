class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n + 1, vector(6, 0));
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<6;j++){
                dp[i][j] = ((i > 1) ? dp[i-1][j] : 1) + dp[i][j-1];
            }
        }
        
        return dp[n][5];
    }
};