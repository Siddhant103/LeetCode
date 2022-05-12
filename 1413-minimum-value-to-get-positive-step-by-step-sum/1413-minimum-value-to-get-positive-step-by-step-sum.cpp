class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum = 0, minSum = 0;
        for (int num: nums) {
            sum += num;
            minSum = min(sum, minSum);
        }
        return -minSum + 1;
    }
};