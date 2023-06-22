class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n < 2) return 0;
        
        vector<int> hold(n);
        vector<int> sold(n);
        hold[0] = -prices[0];
        
        for (int i = 1; i < n; ++i) {
            hold[i] = max(hold[i - 1], sold[i - 1] - prices[i]);
            sold[i] = max(sold[i - 1], hold[i - 1] + prices[i] - fee);
        }

        return sold[n - 1];
    }
};