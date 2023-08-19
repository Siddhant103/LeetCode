/**
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,0);
        
        queue<int> q;
        
        for(int i=0;i<n;i++){
            if(color[i])   
                continue;
            
            color[i]=1;
            q.push(i);
            
            while(!q.empty()){
                int temp = q.front();
                
                for(auto neighbour: graph[temp]){
                    if(color[neighbour]==0){
                        color[neighbour] = -color[temp];
                        q.push(neighbour);
                    }
                    else if(color[neighbour]==color[temp])
                        return false;
                }
                q.pop();
            }
        }
        return true;
    }
};
*/

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0);
        queue<int> q;

        for (int i=0;i<n;i++) {
            if (color[i]) {
                continue;
            }
            color[i] = 1;
            q.push(i);
            
            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (auto it: graph[node]) {
                    if (color[it] == 0) {
                        color[it] = -color[node];
                        q.push(it);
                    } else if (color[it] == color[node]) {
                        return false;
                    }
                }

            }
        }

        return true;
    }
};