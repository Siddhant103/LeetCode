class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        
        while(i >= 0 && nums[i] >= nums[i + 1]) 
            i--;
        
        if(i >= 0){
            int j = nums.size() - 1;
            while(j >= 0 && nums[j] <= nums[i])
                j--;
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
        
        //Reverse from i + 1 to length
        
        int start = i + 1, end = nums.size() - 1;
        while(start < end){
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }
};