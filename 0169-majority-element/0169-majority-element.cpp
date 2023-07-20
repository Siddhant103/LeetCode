class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majElement = nums[0];   
        int count = 1;
        for (int i=1;i<nums.size();i++) {
            if (nums[i] == majElement) {
                count++;
            } else {
                count--;
            }
            
            if (count == 0) {
                majElement = nums[i];
                count = 1;
            }
        }
        return majElement;
    }
};