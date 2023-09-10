class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int diff = nums[n - 1] - nums[n - 2];

        for (int i=1;i<n;i++) {
            diff = min(diff, nums[i] - nums[i - 1]);
        }

        return diff;
    }
};