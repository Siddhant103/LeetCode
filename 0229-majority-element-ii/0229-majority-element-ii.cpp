class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0, count2 = 0, el1 = INT_MIN, el2 = INT_MIN;
        
        for (int i=0; i<nums.size(); i++) {
            if (count1 == 0 && nums[i] != el2) {
                count1 = 1;
                el1 = nums[i];
            } else if (count2 == 0 && nums[i] != el1) {
                count2 = 1;
                el2 = nums[i];
            } else if (nums[i] == el1) {
                count1++;
            } else if (nums[i] == el2) {
                count2++;
            } else {
                count1--;
                count2--;
            }
        }
        
        vector<int> ans;
        int countEl1 = 0, countEl2 = 0, minimumReq = int(nums.size()/3) + 1;
        
        for (int num: nums) {
            if (num == el1) countEl1++;
            if (num == el2) countEl2++;
        }
        if (countEl1 >= minimumReq) ans.push_back(el1);
        if (countEl2 >= minimumReq) ans.push_back(el2);
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};