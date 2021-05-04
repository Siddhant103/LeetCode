class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majCount = 1;
        int majElement = nums[0];
        
        for(int i=1;i<nums.size();i++){
            if(nums[i]==majElement){
                majCount++;
            } else{
                majCount--;
            }
            
            if(majCount==0){
                majCount=1;
                majElement=nums[i];
            }
        }
        
        return majElement;
    }
};