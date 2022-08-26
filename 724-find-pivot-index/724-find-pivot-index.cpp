class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for(int num: nums) {
            sum += num;
        }
        
        int leftSum = 0;
        for (int i=0;i<nums.size();i++) {
            if (leftSum * 2 == sum - nums[i]) {
                return i;
            }
            cout << leftSum << "  " << sum << endl;
            leftSum += nums[i];
        }
        
        return -1;
    }
};