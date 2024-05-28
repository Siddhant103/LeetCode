class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
       int n = s.length();
       vector<int> cost(n);
        
        for (int i = 0; i < n; ++i) {
            cost[i] = abs(s[i] - t[i]);
        }
        
        int i = 0, j = 0, currentCost = 0, maxLength = 0;
        
        // Sliding window approach
        while (j < n) {
            currentCost += cost[j];
            
            while (currentCost > maxCost) {
                currentCost -= cost[i];
                i++;
            }
            
            maxLength = max(maxLength, j - i + 1);
            j++;
        }
        
        return maxLength;
    }
};