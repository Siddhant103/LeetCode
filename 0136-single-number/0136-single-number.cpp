class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xor1 = 0;
        for (int num: nums) {
            xor1 ^= num;
        }
        return xor1;
    }
};