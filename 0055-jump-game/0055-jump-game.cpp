class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = 0;
        for (int i = 0;i < nums.size();i++) {
            if (reach < i) {
                return false;
            }
            if (i + nums[i] > reach) {
                reach = i + nums[i];
            }
        }   
        return true;
    }
};