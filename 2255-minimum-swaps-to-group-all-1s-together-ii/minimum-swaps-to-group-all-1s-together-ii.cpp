class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size();i++)
            if(nums[i]==1)
                count++;
        int result=0;
      
        for(int i=0;i<count;i++)
        {
             if(nums[i]==0)
                 result++;
        }
       
        int ans=result;
        for(int i=1;i<nums.size();i++)
        {
            int j=(i+count-1)%nums.size();
            if(nums[i-1]==0)
                result--;
            if(nums[j]==0)
                result++;
            ans=min(ans,result);
        }
        return ans;
    }
};