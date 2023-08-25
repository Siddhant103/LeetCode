class Solution {
public:
    int getChange(vector<int>& coins, int index, int amount, vector<vector<int>>& dp) {
        if (index < 0) {
            return INT_MAX - 1;
        }
        if (amount <= 0) {
            return 0;
        }
        if (amount == coins[index]) {
            return 1;
        }

        if (dp[amount][index] != -1) {
            return dp[amount][index];
        }
        int take = 0;
        if (amount >= coins[index]) {
            return dp[amount][index] =
            min(
                1 + getChange(coins, index, amount - coins[index], dp),
                getChange(coins, index - 1, amount, dp)
            );
        } 
        return dp[amount][index] = getChange(coins, index - 1, amount, dp);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(amount + 1, vector<int>(n, -1));
        int change = getChange(coins, n - 1, amount, dp);
        if (change == INT_MAX - 1)
            return -1;

        return change;
    }
};