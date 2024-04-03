class Solution {
public:
    bool checkIfPresent(vector<vector<char>> &board, string &word, int index, int i, int j, int n, int m) {
        if (index == word.size()) {
            return true;
        }
        if (i < 0 || j < 0 || i >= n || j >= m || board[i][j] != word[index]) {
            return false;
        }
        char temp = board[i][j];
        board[i][j] = '$';
        bool check = checkIfPresent(board, word, index + 1, i + 1, j, n, m) || 
                checkIfPresent(board, word, index + 1, i, j - 1, n, m) ||
                checkIfPresent(board, word, index + 1, i, j + 1, n, m) ||
                checkIfPresent(board, word, index + 1, i - 1, j, n, m);
        board[i][j] = temp;
        return check;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (board[i][j] == word[0] && checkIfPresent(board, word, 0, i, j, n, m)) {
                    return true;
                }
            }
        }

        return false;
    }
};