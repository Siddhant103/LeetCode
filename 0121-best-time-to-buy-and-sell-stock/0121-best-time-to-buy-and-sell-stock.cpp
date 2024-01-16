class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int minPriceStock = INT_MAX;
        for (int price: prices) {
            if (price < minPriceStock) {
                minPriceStock = price;
            }
            profit = max(profit, price - minPriceStock);
        }
        return profit;
    }
};