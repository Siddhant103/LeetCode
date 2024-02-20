class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xor1 = 0;
        for (int i=0;i<nums.size();i++) {
            xor1 = xor1 ^ nums[i];
            xor1 = xor1 ^ (i+1);
        }
        return xor1;
    }
};