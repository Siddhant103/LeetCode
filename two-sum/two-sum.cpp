class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> vals;
        vector<int> ans;
        int i=0;
        for(i=0;i<nums.size();i++){
            if(vals.find(target-nums[i])!=vals.end()){
                ans.push_back(vals[target-nums[i]]);
                ans.push_back(i);
            } else{
                vals[nums[i]]=i;
            }
        }
        return ans;
    }
};