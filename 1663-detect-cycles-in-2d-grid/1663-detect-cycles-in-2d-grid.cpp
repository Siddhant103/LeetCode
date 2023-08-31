class Solution {
    int n, m;
    bool vis[505][505];
    bool cycle = false;
    int fx[4] = {1, -1, 0, 0};
    int fy[4] = {0, 0, 1, -1};
    vector<vector<char>> g;

public:
    bool containsCycle(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        g = grid;
        memset(vis, false, sizeof(vis));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!vis[i][j]) {
                    dfs(i, j);
                    if(cycle) 
                        return true;
                }
            }
        }
        return false;
    }

    void dfs(int ux, int uy, int px = -1, int py = -1) {
        vis[ux][uy] = true;
        
        for(int i=0; i<4; i++) {
            int vx = ux + fx[i];
            int vy = uy + fy[i];
            if(vx == px && vy == py) 
                continue;
            if(vx >= 0 && vy >= 0 && vx < n && vy < m && g[vx][vy] == g[ux][uy]) {
                if(vis[vx][vy]) {
                    cycle = true;
                    return;
                }
                dfs(vx, vy, ux, uy);
            }  
        }
        return ;
    }
    
};