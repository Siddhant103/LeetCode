class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int num: nums){
            s.insert(num);
        }
        
        int maxLength = 0;
        
        for(int i=0;i<nums.size();i++){
            if(s.find(nums[i]) == s.end())
                continue;
            int prev = nums[i] - 1, next = nums[i] + 1;
            s.erase(nums[i]);
            while(s.find(prev) != s.end()){
                s.erase(prev);
                prev--;
            }
            while(s.find(next) != s.end()){
                s.erase(next);
                next++;
            }
            maxLength = max(maxLength, next - prev - 1);
        }
                            
        return maxLength;
    }
};