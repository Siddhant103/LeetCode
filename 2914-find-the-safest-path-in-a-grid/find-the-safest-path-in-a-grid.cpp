class Solution {
public:
    void minManhattandis(vector<vector<int>>& grid, vector<vector<int>>& vis) {
        int row = grid.size();
        int col = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    vis[i][j] = 0;
                }
            }
        }
        int r[] = {1, -1, 0, 0};
        int c[] = {0, 0, -1, 1};
        while (!q.empty()) {
            int temp_i = q.front().first;
            int temp_j = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int new_i = temp_i + r[i];
                int new_j = temp_j + c[i];

                if (new_i >= 0 && new_i < row && new_j >= 0 && new_j < col &&
                    vis[new_i][new_j] == -1) {
                    vis[new_i][new_j] = 1 + vis[temp_i][temp_j];
                    q.push({new_i, new_j});
                }
            }
        }
    }
    void dfs(int i, int j, int sf, vector<vector<int>>& grid,
             vector<vector<int>>& vis, vector<vector<int>>& dis,bool& ans) {

        if (i == grid.size() - 1 && j == grid[0].size() - 1 && dis[i][j]>=sf) {
                ans=true;
                return;
        }
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
            vis[i][j] == 1 || dis[i][j] < sf) {
            return;
        }
        vis[i][j]=1;
        dfs(i + 1, j, sf, grid, vis, dis,ans);
        dfs(i - 1, j, sf, grid, vis, dis,ans);
        dfs(i, j - 1, sf, grid, vis, dis,ans);
        dfs(i, j + 1, sf, grid, vis, dis,ans);
    } 
    
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        if (grid[0][0] == 1 || grid[row - 1][col - 1] == 1) {
            return 0;
        }
        vector<vector<int>> dis(row, vector<int>(col, -1));
        minManhattandis(grid, dis);
        int ans = 0;
        int s = 0;
        int e = row + col;
        while (s <= e) {
            int mid = (s + e) / 2;
            bool res = false;
            vector<vector<int>> vis(row, vector<int>(col, -1));
            dfs(0, 0, mid, grid, vis, dis,res);
            if (res) {
                ans = max(ans,mid);
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return ans;
    }
}
;