class Solution {
public:
    int solve(int i,int j,vector<int>& nums1, vector<int>& nums2, vector<vector<int>>&dp) {
        if (i<0 || j<0)
            return 0;
        
        if (dp[i][j]!=-1)
            return dp[i][j];
        
        if (nums1[i] == nums2[j])
            return 1+solve(i-1,j-1,nums1,nums2,dp);
        
        int take1 = solve(i-1,j,nums1,nums2,dp);
        int take2 = solve(i,j-1,nums1,nums2,dp);
        
        return dp[i][j] = max(take1,take2);
    }
    
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        
        vector<vector<int>>dp(n,vector<int>(m,-1));
        
        return solve(nums1.size()-1,nums2.size()-1,nums1,nums2,dp);
    }
};