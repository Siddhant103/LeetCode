class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> productBefore(n);
        vector<int> productAfter(n);
        productBefore[0]=1;
        productAfter[n-1]=1;
        
        /*
         1  2  3  4
         1  1  2  6   -  Before
         24 12 4  1   -  After
         
        
        */
        
        for(int i=1, j=n-2;i<n;i++,j--){
            productBefore[i] = productBefore[i-1]*nums[i-1];
            productAfter[j] = productAfter[j+1]*nums[j+1];    
        }
        
        for(int i=0;i<n;i++){
            nums[i] = productBefore[i] * productAfter[i];
        }
        
        return nums;
    }
};