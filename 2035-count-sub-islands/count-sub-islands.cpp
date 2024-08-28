class Solution {
    int dirs[4][2] = {{0,1},{0,-1},{-1,0},{1,0}}, M, N;
    void dfs(vector<vector<int>> &B, int x, int y, int color) {
        if (B[x][y] == color) return;
        B[x][y] = color;
        for (auto &[dx, dy] : dirs) {
            int a = x + dx, b = y + dy;
            if (a < 0 || a >= M || b < 0 || b >= N) continue;
            dfs(B, a, b, color);
        }
    }
public:
    int countSubIslands(vector<vector<int>>& A, vector<vector<int>>& B) {
        M = A.size(), N = A[0].size();
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i][j] == 0) dfs(B, i, j, 0); // sink this island at B[i][j]
            }
        }
        int cnt = 0;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (B[i][j] == 1) {
                    dfs(B, i, j, 0);
                    ++cnt; // count islands in `B`
                }
            }
        }
        return cnt;
    }
};