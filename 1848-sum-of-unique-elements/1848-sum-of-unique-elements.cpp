class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        vector<int> count(101);
        int result = 0;

        for (auto n : nums) {
            count[n]++;
        }

        for (auto i = 1; i <= 100; ++i) {
            if (count[i] == 1) {
                result += i;
            }
        }
            
        return result;
    }
};