class Solution {
public:
    bool detectCycleUtil(unordered_map<int, vector<int>>& adj, vector<int>& visited, int v){
        if(visited[v] == 1){
            return true;
        }
        if(visited[v] == 2){
            return false;
        }
        
        visited[v] = 1;
        for(int i: adj[v]){
            if(detectCycleUtil(adj, visited, i)){
                return true;
            }
        }
        visited[v] = 2;
        return false;
    }
    
    bool detectCycle(unordered_map<int, vector<int>>& adj, int numCourses){
        vector<int> visited(numCourses, 0);
        
        for(int i=0;i<numCourses;i++){
            if(visited[i] == 0 && detectCycleUtil(adj, visited, i)){
                return true;
            }
        }
        
        return false;
    }
    
    void dfs(unordered_map<int, vector<int>>& adj, vector<int>& visited, int v, vector<int>& result){
        visited[v] = true;
        
        for(int i=0;i<adj[v].size();i++){
            if(visited[adj[v][i]] == 0){
                dfs(adj, visited, adj[v][i], result);
            }
        }
        
        result.push_back(v);
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        
        for(vector<int> pre: prerequisites){
            adj[pre[1]].push_back(pre[0]);
        }
        
        vector<int> result;
        //detect cycle
        if(detectCycle(adj, numCourses)){
            return result;
        }
        
        vector<int> visited(numCourses);
        for(int i=0;i<numCourses;i++){
            if(visited[i] == 0){
                dfs(adj, visited, i, result);
            }
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};