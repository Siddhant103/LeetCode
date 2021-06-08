class Solution {
public:
    
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        set<vector<int>> visited;
        return dfs(maze, start, destination, visited);
        
    }
    
    bool dfs(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination, set<vector<int>>& visited){
        if(start == destination)
            return true;
        
        if(visited.find(start) != visited.end())
            return false;
        
        visited.insert(start);
        vector<vector<int>> dirs = {{0, 1},{0, -1},{1, 0},{-1, 0}};
        for(int i=0;i<4;i++){
            vector<int> finalPos = goTillEnd(maze, start, dirs[i]);
            if(finalPos == destination || dfs(maze, finalPos, destination, visited))
                return true;
        }
        
        return false;
    }
    
    vector<int> goTillEnd(vector<vector<int>>& maze, vector<int>& start, vector<int>& dirs){
        int i = start[0] + dirs[0];
        int j = start[1] + dirs[1];
        int m = maze.size();
        int n = maze[0].size();
        if(i < 0 || j < 0 || i >= m || j >= n || maze[i][j] == 1){
            return start;
        }
        vector<int> newStart = {i, j};
        return goTillEnd(maze, newStart, dirs);
    }
};