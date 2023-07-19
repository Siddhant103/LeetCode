class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int start = 0, end = nums.size() - 1;
        //[0,1,2,2,3,0,4,2]
        //2
        while (start < nums.size() && start <= end) {
            if (nums[start] == val) {
                int temp = nums[end];
                nums[end] = nums[start];
                nums[start] = temp;
                end--;
            } else {
                start++;    
            }
        }
        return end + 1;
    }
};