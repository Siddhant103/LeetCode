class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int result = 0;
        unordered_map<int, int> count;
        int currSum = 0;
        count[0] = 1;
        for(int i=0;i<nums.size();i++){
            currSum += nums[i];
            
            if(count.find(currSum - k)!=count.end()){
                result += count[currSum-k];
            }
            
            count[currSum]++;
        }
        
        return result;
    }
};