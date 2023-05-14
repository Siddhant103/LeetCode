class Solution {
public:
    int dp[16400];

    bool isOne(int mask, int p) {
        return ((1 << p) & mask);
    }

    int toOne(int mask, int p) {
        return ((1 << p) | mask);
    }

    int roy(vector<int>& v, int N, int ith, int mask) {
        if (ith * 2 > N)
            return 0;
        
        if (dp[mask] != -1)
            return dp[mask];

        dp[mask] = 0;
        for (int i = 0; i < N; i++) {
            if (isOne(mask, i)) continue;
            for (int j = i + 1; j < N; j++) {
                if (isOne(mask, j)) continue;
                
                dp[mask] = max(
                    dp[mask],
                    ith * __gcd(v[i], v[j]) + 
                    roy(v, N, ith + 1, toOne(toOne(mask, i), j)) 
                );
            }
        }

        return dp[mask];
    }


    int maxScore(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return roy(nums, nums.size(), 1, 0);
    }
};