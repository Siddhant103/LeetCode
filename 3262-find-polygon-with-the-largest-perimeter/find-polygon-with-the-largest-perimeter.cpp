class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        long long prefix = nums[0] + nums[1];
        long long result = -1LL;
        for (int i = 2; i < n; i++) {
            if (prefix > nums[i]) 
                result = prefix + nums[i];
            prefix += nums[i];
        }
        return result;
    }
};