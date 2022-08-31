class Solution {
public:
    int N, M;
    vector<vector<bool> > visited[2];
    
    void dfs(int r, int c, int prev, int t, vector<vector<int>>& matrix) {
        if(r<0 || c<0 || r>=N || c>=M || visited[t][r][c] || matrix[r][c]<prev) {
            return;
        }
        visited[t][r][c] = true;
        dfs(r+1, c, matrix[r][c], t, matrix);
        dfs(r-1, c, matrix[r][c], t, matrix);
        dfs(r, c+1, matrix[r][c], t, matrix);
        dfs(r, c-1, matrix[r][c], t, matrix);
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        // idea search from edges in
        // can traverse to neighbor iff neighbor is >= curr
        // if cell can be reached from each dfs from each ocean then it's a solution
        N = matrix.size();
        vector<vector<int> > res;
        if(N==0) return res;
        M = matrix[0].size();
        visited[0] = vector<vector<bool> > (N, vector<bool>(M, false));
        visited[1] = vector<vector<bool> > (N, vector<bool>(M, false));
        
        //dfs from left and right
        for(int i=0; i<N; i++) {
            dfs(i, 0, matrix[i][0], 0, matrix);
            dfs(i, M-1, matrix[i][M-1], 1, matrix);
        }
        //bottom and top
        for(int i=0; i<M; i++) {
            dfs(0, i, matrix[0][i], 0, matrix);
            dfs(N-1, i, matrix[N-1][i], 1, matrix);
        }
        
        //count the intersection of both searches
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(visited[0][i][j]&&visited[1][i][j])
                    res.push_back({i,j});
            }
        }
        return res;
    }
};