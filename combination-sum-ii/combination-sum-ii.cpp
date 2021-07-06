class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> curr;
        
        dfs(candidates, target, curr, 0, result);
        return result;
    }
    
    void dfs(vector<int>& candidates, int target, vector<int>& curr, int start, vector<vector<int>>& result){
        if(target < 0){
            return ;
        }
        
        if(target == 0){
            result.push_back(curr);
            return;
        }
        
        for(int i=start;i!=candidates.size() && target>=candidates[i];i++){
            if(i == start || candidates[i] != candidates[i - 1]){
                curr.push_back(candidates[i]);
                dfs(candidates, target - candidates[i], curr, i + 1, result);
                curr.pop_back();
            }
        }
    }
};