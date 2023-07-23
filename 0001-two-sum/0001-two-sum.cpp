class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> sumMap;
        for (int i=0;i<nums.size();i++) {
            if (sumMap.find(target - nums[i]) != sumMap.end()) {
                return {i, sumMap[target-nums[i]]};
            }
            sumMap[nums[i]] = i;
        }
        return {0, 0};
    }
};