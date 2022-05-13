class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        if(n == 0)
            return result;
        
        int i = 0, j = n - 1, pos = n - 1;
        while(i <= j){
            if(nums[i] * nums[i] >= nums[j] * nums[j]){
                result[pos--] = nums[i] * nums[i];
                i++;
            } else{
                result[pos--] = nums[j] * nums[j];
                j--;
            }
        }
        
        return result;
    }
};