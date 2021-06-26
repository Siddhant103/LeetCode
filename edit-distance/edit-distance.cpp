class Solution {
    //vector<vector<int>> dp(501, vector<int>(501, -1));
    int dp[501][501];
public:
    int minDistance(string word1, string word2) {
        //dp.resize
        memset(dp, -1, sizeof(dp));
        int m = word1.size(), n = word2.size();
        return editDistance(word1, word2, m, n);
    }
    
    int editDistance(string word1, string word2, int m, int n){
        if(m==0)
            return n;
        else if(n==0)
            return m;
        
        if(dp[m][n] != -1){
            return dp[m][n];
        }
        if(word1[m-1]==word2[n-1]){
            dp[m][n] = editDistance(word1, word2, m-1, n-1);
            return dp[m][n];
        }
        
        dp[m][n] = min(editDistance(word1, word2, m-1, n-1), min(editDistance(word1, word2, m-1, n), editDistance(word1, word2, m, n-1))) + 1;
        
        return dp[m][n];
    }
};