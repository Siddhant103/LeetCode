class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorr = 0;
        for(int num: nums){
            xorr = xorr^num;
        }
        
        return xorr;
    }
};