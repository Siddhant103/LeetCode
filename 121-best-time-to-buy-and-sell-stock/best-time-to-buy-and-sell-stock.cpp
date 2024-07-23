class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX, totalProfit = 0;
        for (int price: prices) {
            minPrice = min(minPrice, price);
            totalProfit = max(totalProfit, price - minPrice);
        }
        return totalProfit;
    }
};