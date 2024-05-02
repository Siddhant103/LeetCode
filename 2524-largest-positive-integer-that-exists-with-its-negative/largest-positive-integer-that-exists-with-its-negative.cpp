class Solution {
public:
    int findMaxK(vector<int>& nums) 
    {
        map<int,int>mp;
        int large=0;
        for(int i=0;i<nums.size();i++)
            mp[nums[i]]++;
        for(auto it : mp)
        {
            if(it.first>0)
            {
                if(mp[(it.first)*-1])
                    large=it.first;
            }
        }
        if(large!=0)
            return large;
        return -1;
    }
};