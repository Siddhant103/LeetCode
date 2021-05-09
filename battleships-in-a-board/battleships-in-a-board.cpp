class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int battleShips = 0;
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j] == 'X')
                    battleShips++;
                    dfs(board, i, j);//to sink that battleship
            }
        }
        
        return battleShips;
    }
    
    void dfs(vector<vector<char>>& board, int i, int j){
        if(i<0 || i>=board.size() || j<0 || j>=board[i].size() || board[i][j]!='X'){
            return;
        }
        
        board[i][j]='.';
        dfs(board,i+1,j);
        dfs(board,i-1,j);
        dfs(board,i,j+1);
        dfs(board,i,j-1);
    }
};