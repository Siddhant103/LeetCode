class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int result = nums[0];
        int currMax = nums[0];
        int currMin = nums[0];
        for(int i=1;i<n;i++){
            int currMaxTemp = currMax;
            currMax = max(nums[i], max(nums[i]*currMax, nums[i]*currMin));
            currMin = min(nums[i], min(nums[i]*currMaxTemp, nums[i]*currMin));
            result = max(result, currMax);
        }
        return result;
    }
};