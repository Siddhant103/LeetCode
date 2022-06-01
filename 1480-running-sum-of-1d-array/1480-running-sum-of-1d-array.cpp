class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int prev = nums[0];
        for (int i=1;i<nums.size();i++) {
            nums[i] = nums[i] + prev;
            prev = nums[i];
        }
        return nums;
    }
};