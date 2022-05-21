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
        /*memset(dp, -1, sizeof(dp));
        
        int coinSum = getNoOfCoins(coins, coins.size()-1, amount);
        if(coinSum == INT_MAX - 1)
            return -1;
        return coinSum;
        */
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1));
        
        for(int i=0;i<=n;i++){
            dp[i][0] = 0;
        }
        
        for(int i=0;i<=amount;i++){
            dp[0][i] = INT_MAX - 1;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(j < coins[i-1]){
                    dp[i][j] = dp[i-1][j];
                } else{
                    dp[i][j] = min(1 + dp[i][j - coins[i-1]], dp[i-1][j]);
                }
            }
        }
        
        return dp[n][amount] == INT_MAX - 1 ? -1 : dp[n][amount];
    }
};