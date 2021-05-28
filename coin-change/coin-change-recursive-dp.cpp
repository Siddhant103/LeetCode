class Solution {
    int dp[20][10001];
public:
    int getNoOfCoins(vector<int>& coins, int n, int amount){
        if(n < 0){
            return INT_MAX - 1;
        }
        
        if(amount <= 0)
            return 0;
        
        if(dp[n][amount] != -1){
            return dp[n][amount];
        }
        if(amount >= coins[n]){
            //consider
            dp[n][amount] = min(1 + getNoOfCoins(coins, n, amount - coins[n]),
                       getNoOfCoins(coins, n - 1, amount));
        }else{
        
            dp[n][amount] = getNoOfCoins(coins, n - 1, amount);
        }
        
        return dp[n][amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        //Recursive + Memoization
        memset(dp, -1, sizeof(dp));
        
        int coinSum = getNoOfCoins(coins, coins.size()-1, amount);
        if(coinSum == INT_MAX - 1)
            return -1;
        return coinSum;
        
    }
};
