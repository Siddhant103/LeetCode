class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        vector<int> topo;
        queue<int> q;

        for (auto edge: prerequisites) {
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }

        for (int i=0;i<numCourses;i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (auto it: adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        
        if (topo.size() == numCourses) {
            return true;
        }
        return false;
    }
};