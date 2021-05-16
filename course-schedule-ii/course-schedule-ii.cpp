class Solution {
public:
    
    bool detectCycleUtil(map<int, vector<int>>& adj, vector<int>& visited, int v){
        if(visited[v]==1)
            return true;
        if(visited[v]==2)
            return false;
        
        visited[v]=1;
        for(int i=0;i<adj[v].size();i++){
            if(detectCycleUtil(adj, visited, adj[v][i]))
                return true;
        }
        
        visited[v]=2;
        return false;
    }
    
    bool detectCycle(map<int, vector<int>>& adj, int n){
        vector<int> visited(n, 0);
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(detectCycleUtil(adj, visited, i))
                    return true;
            }
        }
        
        return false;
    }
    
    void dfs(map<int, vector<int>>& adj, vector<bool>& visited, int v, stack<int>& result){
        visited[v] = true;
        for(int i=0;i<adj[v].size();i++){
            if(!visited[adj[v][i]]){
                dfs(adj, visited, adj[v][i], result);
            }
        }
        result.push(v);
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        map<int, vector<int>> adj;
        vector<int> indegrees;
        
        //make adj list
        for(vector<int> prerequisite: prerequisites){
            adj[prerequisite[1]].push_back(prerequisite[0]);
        }
        //exit(0);
        
        //detect cycle
        vector<int> result;
        stack<int> s;
        if(detectCycle(adj, numCourses)){
            return result;
        }
        
        //topological sort start
        vector<bool> visited(numCourses, false);
        
        for(int i=0;i<numCourses;i++){
            if(visited[i]==false){
                dfs(adj, visited, i, s);
            }
        }
        
        while(!s.empty()){
            result.push_back(s.top());
            s.pop();
        }
        
        return result;
    }
};