class Solution {
public:
    
    int missingNumber(vector<int>& nums, int index){
        return nums[index] - nums[0] - index;
    }
    int missingElement(vector<int>& nums, int k) {
        
        if(k > missingNumber(nums, nums.size()-1)){
            return nums[nums.size() - 1] + k - missingNumber(nums, nums.size() - 1);
        }
        
        int left = 0;
        int right = nums.size()-1;
        
        while(left < right){
            int mid = left + (right - left) / 2;
            if(missingNumber(nums, mid) < k){
                left = mid + 1;
            } else{
                right = mid;
            }
        }
        
        return nums[left-1] + k - missingNumber(nums, left - 1);
    }
};