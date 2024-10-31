class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        using ll = long long;
        
        int m = robot.size();
        int n = factory.size();
        ll MAX = 1e15;
        vector<vector<ll>> dp(m+1, vector<ll>(n+1, MAX));
        
        // initial condition, cost of covering 0 robot with first j factory is 0
        dp[0][0] = 0;
        for (int j = 1; j <= n; ++j) dp[0][j] = 0;
        
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        
        for (int j = 1; j <= n; ++j) {
            int f = factory[j-1][0], d = factory[j-1][1];
            for (int i = 1; i <= m; ++i) {
                // if not cover any robot
                dp[i][j] = dp[i][j-1];
                
                // try to enumerate cases for current factory
                // there are at most limit cases or if there's not enough robots
                ll subtotal = 0;
                for (int k = 1; k <= min(d, i); ++k) {
                    subtotal += llabs((ll)f - robot[i-k]);
                    dp[i][j] = min(dp[i][j], dp[i-k][j-1] + subtotal);
                }
            }
        }
        
        return dp[m][n];
    }
};