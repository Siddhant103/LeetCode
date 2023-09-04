class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) 
    {
        // Construct the board
        char grid[3][3] = {};
        for(int i=0; i<moves.size(); i++)
        {
            int row = moves[i][0];
            int col = moves[i][1];
            if(i % 2 == 0)
                grid[row][col] = 'X';   //A
            else
                grid[row][col] = 'O';   //B
        }

        // Check the winner
        for(int i=0; i<3; i++)
        {
            if(grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2])    //row
            {
                if(grid[i][0] == 'X') return "A";
                if(grid[i][0] == 'O') return "B";
            }
            if(grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i])    //col
            {
                if(grid[0][i] == 'X') return "A";
                if(grid[0][i] == 'O') return "B";
            }
        }
        if(grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2])    //diag1
        {
            if(grid[1][1] == 'X') return "A";
            if(grid[1][1] == 'O') return "B";
        }
        if(grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0])    //diag2
        {
            if(grid[1][1] == 'X') return "A";
            if(grid[1][1] == 'O') return "B";
        }

        return (moves.size() == 9) ? "Draw" : "Pending";
    }
};