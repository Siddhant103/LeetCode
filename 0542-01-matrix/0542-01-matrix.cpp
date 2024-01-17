class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<vector<int>> result(n, vector<int>(m, 0));
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                if (mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    visited[i][j] = 1;
                }
            }
        }
        
        while (!q.empty()) {
            auto temp = q.front(); q.pop();
            int x = temp.first.first, y = temp.first.second, steps = temp.second;
            result[x][y] = steps;
            for (auto dir: dirs) {
                int dx = x + dir[0];
                int dy = y + dir[1];
                if (dx >= 0 && dy >= 0 && dx < n && dy < m && visited[dx][dy] == 0) {
                    visited[dx][dy] = 1;
                    q.push({{dx, dy}, steps + 1});
                }
            }
        }
        
        return result;
    }
};