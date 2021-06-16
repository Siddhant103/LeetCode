class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        backtrack(nums, 0, result);
        
        return result;
    }
    
    void backtrack(vector<int>& nums, int pos, vector<vector<int>>& result){
        if(pos == nums.size() - 1){
            result.push_back(nums);
            return;
        }
        
        for(int i = pos ; i < nums.size() ; i++){
            swap(nums[pos], nums[i]);
            backtrack(nums, pos + 1, result);
            swap(nums[pos], nums[i]);
        }
        
        return;
    }
};