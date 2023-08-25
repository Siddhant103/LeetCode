class Solution {
public:
    
    int fun(string& s1,string& s2,string& s3,int p1,int p2,int p3, vector<vector<int>>& dp) {
        
        if(p1 + p2 == s3.size()) {
            return true;
        }
        
        if(dp[p1][p2] != -1){
            return dp[p1][p2];
        }
        
        bool res = false;
        
        if(p1 != s1.size() && s1[p1] == s3[p3]) 
            res |= fun(s1, s2, s3, p1+1, p2, p3+1, dp);
        if(p2 != s2.size() && s2[p2] == s3[p3]) 
            res |= fun(s1, s2, s3, p1, p2+1, p3+1, dp);
        
        return dp[p1][p2] = res;
    }
    bool isInterleave(string s1, string s2, string s3) {
        
        if(s1.size() + s2.size()!=s3.size()){
            return false;
        }
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        
        return fun(s1,s2,s3,0,0,0, dp);
        
    }

    
};