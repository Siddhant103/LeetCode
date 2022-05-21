class Solution {
    vector<vector<int>> dirs {{1, 0}, {0, -1}, {-1 ,0}, {0, 1}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int, int>> q;
        int oranges = 0;
        
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < m;j++) {
                if (grid[i][j] == 1 || grid[i][j] == 2) {
                    oranges++;
                }
                if (grid[i][j] == 2) {
                    q.push(make_pair(i, j));
                }
            }
        }
        
        int time = 0;
        if (oranges == 0) {
            return time;
        }
        
        int rotten = 0;
        while (!q.empty()) {
            int s = q.size();
            rotten += s;
            if (rotten == oranges) {
                return time;
            }
            
            time++;
            while (s--) {
                auto temp = q.front(); 
                q.pop();
                for (auto dir: dirs) {
                    int x = dir[0] + temp.first;
                    int y = dir[1] + temp.second;
                    if(x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == 1){
                        grid[x][y] = 2;
                        q.push(make_pair(x, y));
                    }
                }
            }
        }
        
        return -1;
    }
};