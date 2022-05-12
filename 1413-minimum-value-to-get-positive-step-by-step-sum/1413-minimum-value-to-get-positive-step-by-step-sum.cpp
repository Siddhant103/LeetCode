class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum = 1, ans = 1;
        for (int num: nums) {
            sum += num;
            if (sum < 1) {
                ans += abs(sum) + 1;
                sum = 1;
            }
        }
        return ans;
    }
};