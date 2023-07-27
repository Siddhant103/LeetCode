class Solution {
public:
    void findCombinations(int index, vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& temp) {
        if(index == candidates.size()) {
            if (target == 0) {
                ans.push_back(temp);
            }
            return;
        }
        if (candidates[index] <= target) {
            temp.push_back(candidates[index]);
            findCombinations(index, candidates, target - candidates[index], ans, temp);
            temp.pop_back();
        }
        findCombinations(index + 1, candidates, target, ans, temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> singleAns;
        findCombinations(0, candidates, target, ans, singleAns);
        return ans;
    }
};