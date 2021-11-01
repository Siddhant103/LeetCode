class Solution {
public:
    void dfs(vector<vector<char>>& g,int r,int c){
        if(r < 0 || c < 0 || r >= g.size() || c >= g[0].size() || g[r][c]!='O') return;
        
        g[r][c]='A';
        
        dfs(g,r+1,c);
        dfs(g,r-1,c);
        dfs(g,r,c+1);
        dfs(g,r,c-1);
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<m;i++){
            dfs(board,0,i);
            dfs(board,n-1,i);
        }
        for(int i=0;i<n;i++){
            dfs(board,i,0);
            dfs(board,i,m-1);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='A'){
                   board[i][j]='O'; 
                }else{
                    board[i][j]='X'; 
                }
            }
        }
    }
};