class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1, majElement = nums[0];
        
        for (int num: nums) {
            if (num == majElement) {
                count++; 
            } else {
                count--;
            }
            
            if (count == 0) {
                majElement = num;
                count = 1;
            }
        }
        
        return majElement;
    }
};