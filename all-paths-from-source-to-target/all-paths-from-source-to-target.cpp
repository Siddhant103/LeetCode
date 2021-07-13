class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> curr;
        dfs(graph, result, curr, 0);
        return result;
    }
    
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& result, vector<int>& curr, int u){
        curr.push_back(u);
        if(u == graph.size() - 1){
            result.push_back(curr);
        } else{
            for(int v: graph[u]){
                dfs(graph, result, curr, v);
            }
        }
        curr.pop_back();
    }
};