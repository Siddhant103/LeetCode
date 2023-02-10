class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if(n == 0)
            return 0;
        int m = grid[0].size();
        
        queue<pair<int, int>> q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    q.push({i, j});
                }
            }
        }
        
        if(q.size() == 0 || q.size() == n * m)
            return -1;
        
        int level = -1;
        vector<vector<int>> dirs{{0, 1},{1, 0},{0, -1},{-1, 0}};
        
        while(!q.empty()){
            level++;
            int qsize = q.size();
            while(qsize--){
                auto temp = q.front(); q.pop();
                for(auto dir: dirs){
                    int x = temp.first + dir[0], y = temp.second + dir[1];
                    if(x < 0 || y < 0 || x >= n || y >= m || grid[x][y] == 1){
                        continue;
                    }
                    q.push({x, y});
                    grid[x][y]++;
                }
            }
        }
        
        return level;
    }
};