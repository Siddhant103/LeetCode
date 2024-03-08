class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> m;
        int maxCount = INT_MIN;
        int maxNums = 0;
        for (int num: nums) {
            m[num]++;
            if (m[num] > maxCount) {
                maxCount = m[num];
            }
        }
        

        for (auto it: m) {
            if (it.second == maxCount) {
                maxNums += it.second;
            }
        }
        
        return maxNums;
    }
};