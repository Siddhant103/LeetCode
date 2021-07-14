class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        int level = -1;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    q.push(make_pair(i, j));
                }        
            }
        }
        
        if(q.size() == 0 || q.size() == n * m){
            return -1;
        }
        
        vector<vector<int>> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        while(q.size()){
            level++;
            int qsize = q.size();
            
            while(qsize--){
                pair<int, int> curr = q.front(); q.pop();
                
                for(int i=0;i<4;i++){
                    int new_row = curr.first + dir[i][0];
                    int new_col = curr.second + dir[i][1];
                    if(new_row < 0 || new_col < 0 || new_row >= n || new_col >= m || grid[new_row][new_col] == 1){
                        continue;
                    }
                    
                    q.push(make_pair(new_row, new_col));
                    grid[new_row][new_col]++;
                }
            }
        }
        
        return level;
    }
};