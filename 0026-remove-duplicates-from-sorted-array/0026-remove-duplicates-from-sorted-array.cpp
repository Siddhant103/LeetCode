class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0, itr;
        for (itr = 1;itr<nums.size();itr++) {
            if (nums[itr] != nums[index]) {
                nums[index + 1] = nums[itr];
                index++;
            }
        }
        return index+1;
    }
};