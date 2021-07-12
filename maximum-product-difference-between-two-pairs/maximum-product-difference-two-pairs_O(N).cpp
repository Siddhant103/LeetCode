class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int min1 = 10001, min2 = 10001, max1 = 0, max2 = 0;
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            if(nums[i] <= min2){
                if(nums[i] <= min1){
                    min2 = min1;
                    min1 = nums[i];
                } else{
                    min2 = nums[i];
                }
            }
            
            if(nums[i] >= max2){
                if(nums[i] >= max1){
                    max2 = max1;
                    max1 = nums[i];
                } else{
                    max2 = nums[i];
                }
            }
        }
        
        cout << min1 << " " << min2 << " " << max1 << " " << max2 << endl;
        
        return max1 * max2 - min1 * min2;
    }
};
