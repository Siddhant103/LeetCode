class Solution {
public:
    int getLastOccurance(vector<int>& nums, int target){
        int left = 0;
        int right = nums.size() - 1;
        int res = -1;
        
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (nums[mid] == target) {
                res = mid;
                left = mid+1;
            } else if (nums[mid] > target) {
                right = mid-1;
            } else if (nums[mid] < target) {
                left = mid+1;
            }
        }
        
        return res;
    }
    
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int index = 0, start = 0;
        
        while (index<n) {
            nums[start] = nums[index];
            start++;
            int lastIndex = getLastOccurance(nums, nums[index]);
            index += (lastIndex - index + 1);
        }
        
        return start;
    }
};