class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> graph(n + 1);
        for(auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<int> dist1(n + 1, INT_MAX);
        vector<int> dist2(n + 1, INT_MAX);
        dist1[1] = 0; 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
        vector<int> freq(n + 1, 0); 
        pq.push({0, 1}); // {timeTaken, node}
        while(!pq.empty()) {
            auto [timeTaken, node] = pq.top();
            pq.pop();
            freq[node]++;
            if(node == n && freq[n] == 2) {
                return timeTaken;
            }
			int signal = timeTaken/change;
            if(signal % 2 == 1) {
                timeTaken = change * (signal + 1) + time;
            } else {
                timeTaken = timeTaken + time;
            }
            for(int& neighbour : graph[node]) {
                if(dist1[neighbour] > timeTaken) {
                    dist2[neighbour] = dist1[neighbour];
                    dist1[neighbour] = timeTaken;
                    pq.push({timeTaken, neighbour});
                } else if(dist2[neighbour] > timeTaken && dist1[neighbour] != timeTaken) {
                    dist2[neighbour] = timeTaken;
                    pq.push({timeTaken, neighbour});
                }
            }
        }
        return 0;
    }
};