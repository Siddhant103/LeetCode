class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int result = 0, start = 0;
        int n = nums.size();
        
        for (int i=0;i<n;i++) {
            m[nums[i]]++;
            while (m[nums[i]] > k) {
                m[nums[start]]--;
                start++;
            }
            result = max(result, i - start + 1);
        }
        return result;
    }
};