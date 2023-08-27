class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        int degree=0;
        int shortest=nums.size();

        for (int i=0;i<nums.size();i++) 
            mp[nums[i]].push_back(i);
        
        for (auto it=mp.begin();it!=mp.end();it++) 
            degree = max(degree,int(it->second.size()));
        
        for (auto it=mp.begin();it!=mp.end();it++) {
            if(it->second.size() == degree) {
                shortest = min(shortest,it->second.back()-it->second[0]+1);
            }
        }
        
        return shortest;
    }
};