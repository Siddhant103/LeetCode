class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        
        vector<vector<int>> ans;
        queue<pair<int, int>> q;
        q.push({rCenter, cCenter});
        vector<vector<int>> dirs{{0,1}, {1, 0}, {0, -1}, {-1, 0}};
        bool visited[102][102] = {0};
        visited[rCenter][cCenter] = true;
        
        while(q.size()){
            int qsize = q.size();
            while(qsize--){
                pair<int, int> temp = q.front(); q.pop();
                ans.push_back({temp.first, temp.second});
                for(int i=0;i<4;i++){
                    int new_row = temp.first + dirs[i][0];
                    int new_col = temp.second + dirs[i][1];
                    if(new_row >= 0 && new_col >= 0 && new_row < rows && new_col < cols && visited[new_row][new_col] == 0){
                        q.push({new_row, new_col});
                        visited[new_row][new_col] = true;
                    }
                }
            }
        }
        
        return ans;
    }
};