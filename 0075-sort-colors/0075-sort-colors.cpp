class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, j = 0, n = nums.size();
        int k = n - 1;
        
        while (j <= k) {
            if (nums[j] == 2) {
                swap(nums[j], nums[k]);
                k--;
            } else if (nums[j] == 1) {
                j++;
            } else if (nums[j] == 0) {
                swap(nums[i], nums[j]);
                i++;
                j++;
            }
        }
    }
};