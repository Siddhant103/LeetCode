class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if(s.size() == 0)
            return 0;
        
        string s_rev(s.rbegin(), s.rend());
        
        int n = s.size();
        int m = n;
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1] == s_rev[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[n][m];
    }
};