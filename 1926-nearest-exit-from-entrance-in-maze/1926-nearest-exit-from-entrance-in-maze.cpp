class Solution {
public:
    int dx[4] = {1 , -1 ,  0 , 0};
    int dy[4] = {0 ,  0 , -1 , 1};
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        queue<pair<int, int>> q;
        int n = maze.size() , m = maze[0].size();
        vector<vector<bool>> visited(n , vector<bool>(m, 0));   
        
        visited[entrance[0]][entrance[1]] = 1;
        q.push({entrance[0] , entrance[1]});
        
        int level = 0;
        
        while( !q.empty() ) {
            
            int size = q.size();
            level++;
            
            while( size-- ) {
                
                pair<int, int> p = q.front();
                q.pop();
                
                for( int i = 0; i < 4; i++ ){
                    
                    int new_row = p.first+dx[i], new_col = p.second+dy[i];
                    
                    if( new_row >= 0 and new_col >= 0 and new_row < n and new_col < m){
                        
                        if(maze[new_row][new_col] != '.') 
                            continue;
                        if(visited[new_row][new_col]) 
                            continue;    
                        
                        if( new_row == 0 or new_col==0 or new_row == n-1 or new_col == m-1) 
                            return level; 
                        
                        visited[new_row][new_col] = 1;
                        q.push({new_row, new_col});
                    }
                }
            }
        }
        return -1;
    }
};