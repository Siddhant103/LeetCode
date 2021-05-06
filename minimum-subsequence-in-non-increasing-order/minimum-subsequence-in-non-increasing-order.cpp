class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        vector<int> result;
        sort(nums.begin(), nums.end());
        int sum = 0;
        for(int i=0;i<nums.size();i++)
            sum += nums[i];
        
        int sumSub = 0;
        for(int i=nums.size()-1;i>=0;i--){
            sumSub += nums[i];
            sum -= nums[i];
            result.push_back(nums[i]);
            if(sumSub>sum)
                break;
        }
        //reverse(result.begin(), result.end());
        
        return result;
    }
};