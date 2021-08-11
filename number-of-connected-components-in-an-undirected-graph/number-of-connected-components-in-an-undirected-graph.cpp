class Solution {
public:
    void dfs(int v, vector<vector<int>>& adj, vector<int>& visited){
        visited[v] = 1;
        for(auto neighbour: adj[v]){
            if(visited[neighbour] == -1){
                dfs(neighbour, adj, visited);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n, vector<int>(0));
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int> visited(n, -1);
        
        int components = 0;
        for(int i=0;i<n;i++){
            if(visited[i] == -1){
                components++;
                dfs(i, adj, visited);
            }
        }
        
        return components;
    }
};