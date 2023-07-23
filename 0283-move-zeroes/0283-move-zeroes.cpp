class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index = 0, itr=0;
        while (itr < nums.size()) {
            if (nums[itr] != 0) {
                nums[index] = nums[itr];
                index++;
            }
            itr++;
        }
        
        while (index < nums.size()) {
            nums[index++] = 0;
        }
    }
};