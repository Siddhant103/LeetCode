class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        vector<vector<int>> result;
        getCombinations(candidates, target, curr, result, 0);
        return result;
    }
    
    void getCombinations(vector<int>& candidate, int target, vector<int>& curr, vector<vector<int>>& result, int begin){
        
        if(target==0){
            result.push_back(curr);
            return;
        }
        
        for(int i=begin; i!=candidate.size() && target>=candidate[i];++i){
            curr.push_back(candidate[i]);
            getCombinations(candidate, target-candidate[i], curr, result, i);
            curr.pop_back();
        }
    }
};