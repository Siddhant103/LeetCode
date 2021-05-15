class Solution {
public:
    
    int orangesRotting(vector<vector<int>>& grid) {
        
        int row = grid.size();
        int col = grid[0].size();
        int time = 0;
        int fresh = 0;
        queue<pair<int, int>> q;
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j] == 2){//calculate time
                    q.push({i, j});
                } else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        
        if(fresh == 0)
            return 0;
        vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                pair<int, int> temp = q.front();
                q.pop();
                for(vector<int> dir: directions){
                    int dx = temp.first + dir[0];
                    int dy = temp.second + dir[1];
                    
                    if(dx>=0 && dx<row && dy>=0 && dy<col && grid[dx][dy]==1){
                        grid[dx][dy]=2;
                        q.push({dx, dy});
                        fresh--;
                    }
                }
            }
            time++;
        }
        
        if(fresh>0)
            return -1;
        return time-1;
    }
};