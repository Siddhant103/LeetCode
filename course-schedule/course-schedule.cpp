class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n, vector<int>());
        for(vector<int>& pre: prerequisites){
            adj[pre[0]].push_back(pre[1]);
        }
        
        vector<int> visited(n, 0);
        for(int i=0;i<n;i++){
            if(visited[i]==0 && !dfs(adj, visited, i))
                return false;
        }
        
        return true;
    }
    
    bool dfs(vector<vector<int>>& adj, vector<int>& visited, int v){
        if(visited[v]==1)
            return false;
        if(visited[v]==0){
            visited[v]=1;
            for(int next: adj[v]){
                if(!dfs(adj, visited, next))
                    return false;
            }
        }
        visited[v]=2;
        
        return true;
    }
};