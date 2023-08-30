class Solution {
public:
 long long minimumReplacement(vector<int>& nums) 
    {
        long long int ans=0;
        int n=nums.size();
        int prev=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
           if(nums[i]>prev)
           {
               long long int op=nums[i]/prev;
               if(nums[i]%prev==0)
               {
                   ans+=(long long) op-1;
               }
               else
               {
                   ans+=(long long )op;
                   prev=nums[i]/(op+1);
               }
           }
            else
            {
                prev=nums[i];
            }
        }
        return ans;
        
    }
};