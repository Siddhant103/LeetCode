class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i, j, k;
        vector<vector<int>> result;
        for (k=0;k<n-1;k++) {
            i = k + 1;
            j = n - 1;
            while (i < j) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0) {
                    i++;
                } else if (sum > 0) {
                    j--;
                } else {
                    vector<int> triplet = {nums[i], nums[j], nums[k]};
                    i++;
                    j--;
                    result.push_back(triplet);
                    while (i < j && nums[i - 1] == nums[i]) {
                        i++;
                    }
                    while (i < j && nums[j + 1] == nums[j]) {
                        j--;
                    }
                }
            }
            while (k < n - 1 && nums[k] == nums[k + 1]) {
                k++;
            }
        }
        return result;
    }
};