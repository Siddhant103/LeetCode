class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cmSum = 0;
        int cntSubArray = 0;
        map<int, int> subArrays;
        
        subArrays[0]++;
        
        for(int i=0;i<nums.size();i++){
            cmSum += nums[i];
            if(subArrays.find(cmSum-k)!=subArrays.end()){
                cntSubArray += subArrays[cmSum-k];
            }
            subArrays[cmSum]++;            
        }
        
        return cntSubArray;
    }
};