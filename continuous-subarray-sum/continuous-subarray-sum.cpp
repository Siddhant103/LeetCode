class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        unordered_map<int,int> m = {{0,-1}};
        int sum = 0;
        
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            sum %= k;
            if(m.count(sum)){
                if(i-m[sum] > 1){
                    return true;
                }
            } else{
                m[sum] = i;
            }
        }
        return false;
    }
};