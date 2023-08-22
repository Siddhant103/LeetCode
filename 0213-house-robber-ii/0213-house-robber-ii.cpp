class Solution {
public:
    int dp[101][2];

    int solve(vector<int>& nums, int n, int pos, bool isValid){
        if(pos>=n) return 0;
        if(dp[pos][isValid] != -1) return dp[pos][isValid];
        
        int rob = 0, notrob = 0;
        if(isValid) rob = nums[pos] + solve(nums,n,pos+1,false); //can rob, only when the previous house is not robbed
        notrob = solve(nums,n,pos+1,true); //cannot rob
        
        return dp[pos][isValid] = max(rob,notrob);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0]; //exception condition, which we have to handle separately
		//when n==1, case1 and case2 return 0 but we have to select the house as there are no adjecent house.
        
        memset(dp,-1,sizeof(dp));
		//case 1: rob from 0...n-1, because all houses are in circular so nth is adjecent to 0th house
        int case1 = solve(nums,n-1,0,true);
		
        memset(dp,-1,sizeof(dp));
		//case 2: rob from 1...n,
        int case2 = solve(nums,n,1,true);
		
		//return maximum between case1 & case2
        return max(case1,case2);
    }
};