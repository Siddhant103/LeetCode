class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majElement = nums[0];
        int majCount = 1;
        
        for(int i=1;i<nums.size();i++){
            if(nums[i] == majElement){
                majCount++;
            } else{
                majCount--;
            }
            
            if(majCount==0){
                majElement=nums[i];
                majCount=1;
            }
        }
        
        return majElement;
    }
};