class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        
        int minVal = INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target && abs(i-start)<minVal)
                minVal = abs(i-start);
        }
        return minVal;
    }
};