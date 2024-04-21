class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination)
            return true;
        unordered_map<int,list<int>> adj;
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        queue<int> q;
        vector<int> visited(n);
        q.push(source);
        visited[source] = true;

        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(auto neighbour:adj[front]){
                if(!visited[neighbour]){
                    if(neighbour == destination)
                        return true;
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }
        return false;
    }
};