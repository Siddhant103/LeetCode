class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT_MAX;
        int sum = 0;
        int left = 0;
        
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            while(sum >= target){
                result = min(result, i+1-left);
                sum -= nums[left];
                left++;
            }
        }
        
        return result!=INT_MAX ? result: 0;
    }
};