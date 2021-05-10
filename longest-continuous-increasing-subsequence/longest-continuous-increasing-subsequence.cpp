class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return 1;
        vector<int> dp(nums.size(), 0);
        dp[0]=1;
        int maxS = 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                dp[i] = dp[i-1]+1;
            } else{
                dp[i] = 1;
            }
            maxS = max(maxS, dp[i]);
        }
        
        return maxS;
    }
};