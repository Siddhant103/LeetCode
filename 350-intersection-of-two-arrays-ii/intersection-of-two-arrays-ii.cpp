class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> vals;
        vector<int> ans;
        int i;
        for(i=0;i<nums1.size();i++){
            vals[nums1[i]]++;
        }
        for(i=0;i<nums2.size();i++){
            if(vals.find(nums2[i])!=vals.end() && vals[nums2[i]]!=0){
                ans.push_back(nums2[i]);
                vals[nums2[i]]--;
            }
        }
        return ans;
    }
};