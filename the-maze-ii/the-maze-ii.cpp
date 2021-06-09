class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid, vector<int>& start, vector<int>& destination) {
        int rows = grid.size();
        if(rows==0)
            return -1;
        int cols = grid[0].size();
        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
        queue<pair<int,int>> q;
        q.push({start[0], start[1]});
        vector<pair<int,int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};
        dist[start[0]][start[1]] = 0;
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(auto it: dirs)
            {
                int r= x + it.first;
                int c= y + it.second;
                int count = 0;
                while(r>=0 && c>=0 && r<rows && c<cols && grid[r][c] == 0)
                {
                    r+= it.first;
                    c+= it.second;
                    count+=1;
                }

                if(dist[x][y] + count < dist[r-it.first][c-it.second])
                {
                    dist[r-it.first][c-it.second] = dist[x][y] + count;
                    q.push({r-it.first, c-it.second});
                }
            }

        }

        if(dist[destination[0]][destination[1]] == INT_MAX)
            return -1;

        return dist[destination[0]][destination[1]];
    }
    
};