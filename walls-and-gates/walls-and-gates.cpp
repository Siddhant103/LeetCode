class Solution {
public:
    
    void dfs(vector<vector<int>>& rooms, int i, int j, int distance){
        if(i<0 || i>=rooms.size() || j<0 || j>=rooms[0].size() || rooms[i][j]<distance || rooms[i][j]==-1){
            return;
        }
        
        rooms[i][j] = distance;
        dfs(rooms, i+1, j, distance+1);
        dfs(rooms, i-1, j, distance+1);
        dfs(rooms, i, j+1, distance+1);
        dfs(rooms, i, j-1, distance+1);
    }
    
    void wallsAndGates(vector<vector<int>>& rooms) {
        int row = rooms.size();
        int col = rooms[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> directions {{-1,0},{1,0},{0,1},{0,-1}};
        int distance = 0;
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(rooms[i][j] == 0){
                    //start a dfs with initial distance=0 to all available points
                    q.push({i,j});
                }
            }
        }
        
        while(!q.empty()){
            pair<int, int> temp = q.front();
            q.pop();
            int r = temp.first;
            int c = temp.second;
            for(vector<int> dir: directions){
                int newR = r + dir[0];
                int newC = c + dir[1];
                if(newR<0 || newC<0 || newR>=row || newC>=col || rooms[newR][newC] <= rooms[r][c]+1){
                    continue;
                }
                rooms[newR][newC] = rooms[r][c]+1;
                q.push({newR, newC});
            }
        }
    }
};