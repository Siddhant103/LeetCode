class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int row = board.size();
        int col = board[0].size();
        
        vector<vector<int>> directions = {{1,-1},{1,0},{1,1},{0,-1},{0,1},{-1,-1},{-1,0},{-1,1}};
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                int alive = 0;
                for(vector<int> direction: directions){
                    int dx = i + direction[0];
                    int dy = j + direction[1];
                    if(dx>=0 && dx<row && dy>=0 && dy<col && (board[dx][dy]==1 || board[dx][dy]==-1)){
                        alive++;
                    }
                }
                cout<<alive<<" ";
                // Rules 1 and 3: -1 indicates a cell that was live but now is dead.
                if (board[i][j] == 1 && (alive < 2 || alive > 3))
                    board[i][j] = -1;
                
                // Rule 4: 2 indicates a cell that was dead but now is live.
                if (board[i][j] == 0 && alive == 3)
                    board[i][j] = 2;
            }
        }
        
        cout<<endl;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                cout<<board[i][j]<<" ";
                if(board[i][j]>=1){
                    board[i][j] = 1;
                }
                else{
                    board[i][j] = 0;
                }
            }
            cout<<endl;
        }
    }
};