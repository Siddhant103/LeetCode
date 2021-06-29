class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxLen =  0, start = 0, end = 0;
        int flippedCount = 0;
        
        while(end < nums.size()){
            if(nums[end] == 1){
                end++;
            } else if(nums[end] == 0){
                if(flippedCount < k){
                    flippedCount++;
                    end++;    
                } else{
                    while(flippedCount >= k){
                        if(nums[start] == 0){
                            flippedCount--;
                        }
                        start++;
                    }
                }
            }
            
            maxLen = max(maxLen, end - start);
        }
        
        return maxLen;
    }
};