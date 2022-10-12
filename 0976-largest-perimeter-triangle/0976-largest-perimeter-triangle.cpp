class Solution {
public:
    bool isTriangle(vector<int>& nums, int i)
    {
        if((nums[i-2]+nums[i-1])>nums[i])
            return true;
        return false;
    }
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxP = 0;
        for(int i=2;i<nums.size();i++)
        {
            if(isTriangle(nums,i))
                maxP = max(maxP,(nums[i-2]+nums[i-1]+nums[i]));
        }
        return maxP;
    }
};