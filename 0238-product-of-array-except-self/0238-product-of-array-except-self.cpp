class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> result(n);
        result[0] = 1;
        /*
         1  2  3  4
         1  1  2  6   -  Before
         24 12 4  1   -  After        
        */
        
        for(int i=1;i<n;i++){
            result[i] = result[i-1]*nums[i-1];
        }
        
        int R=1;
        for(int i=n-1;i>=0;i--){
            result[i] = result[i] * R;
            R = R * nums[i];
        }
        
        return result;
    }
};