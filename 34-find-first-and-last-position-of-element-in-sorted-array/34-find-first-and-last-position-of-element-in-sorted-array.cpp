class Solution {
public:
    int binarySearchStart(vector<int>& nums, int left, int right, int target){
        int ans = -1;
        while(left<=right){
            int mid = left + (right-left)/2;
            if(nums[mid]>=target){
                right = mid-1;
            } else{
                left = mid+1;
            }
            if(nums[mid]==target)
                ans = mid;
        }
        return ans;
    }
    
    int binarySearchEnd(vector<int>& nums, int left, int right, int target){
        int ans = -1;
        while(left<=right){
            int mid = left + (right-left)/2;
            if(nums[mid]<=target){
                left = mid+1;
            } else{
                right = mid-1;
            }
            if(nums[mid]==target)
                ans = mid;
        }
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int startIndex = binarySearchStart(nums, 0, nums.size()-1, target);
        int endIndex = binarySearchEnd(nums, 0, nums.size()-1, target);
        cout<<startIndex;
        return {startIndex,endIndex};
    }
};