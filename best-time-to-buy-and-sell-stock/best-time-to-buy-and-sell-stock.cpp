class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minVal = INT_MAX;
        int maxVal = 0;
        
        for(int i=0;i<prices.size();i++){
            if(prices[i]<minVal)
                minVal = prices[i];
            else if(prices[i]-minVal > maxVal)
                maxVal = prices[i]-minVal;
        }
        
        return maxVal;
    }
};