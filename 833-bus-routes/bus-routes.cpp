class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) {
            return 0;
        }

        unordered_map<int, vector<int>> adj;

        for (int route = 0; route < routes.size(); route++) {
            for (auto &stop: routes[route]) {
                adj[stop].push_back(route);
            }
        }

        queue<int> q;
        vector<bool> visited(501, false);
        int busCount = 1;
        for (auto &route: adj[source]) {
            q.push(route);
            visited[route] = true;
        }

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int route = q.front();
                q.pop();

                for (auto &stop: routes[route]) {
                    if (stop == target) {
                        return busCount;
                    }
                    for (auto &nextRoute: adj[stop]) {
                        if (visited[nextRoute] == false) {
                            visited[nextRoute] = true;
                            q.push(nextRoute);
                        }
                    }
                }
            }
            busCount++;
        }

        return -1;
    }
};