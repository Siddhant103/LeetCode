class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        
        if(grid[0][0]==1 || grid[n-1][n-1]==1)
            return -1;
        
        int adjacents[8][8]={{1,1}, {0,1},{1,0},{0,-1},{-1,0},{-1, -1},{1, -1},{-1, 1}};
        
        queue<pair<int,int>> q;
        
        q.push(make_pair(0,0));
        grid[0][0]=1;
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            
            if(row==n-1 && col==n-1)
                return grid[row][col];
            
            for(auto adjacent : adjacents){
                int nrow = row+adjacent[0];
                int ncol = col+adjacent[1];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==0){
                    q.push(make_pair(nrow,ncol));
                    grid[nrow][ncol]=grid[row][col]+1;
                }
            }
            q.pop();
        }
        
        return -1;
    }
};