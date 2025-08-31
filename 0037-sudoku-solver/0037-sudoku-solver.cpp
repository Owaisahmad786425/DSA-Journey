class Solution {
 bool isValid(vector<vector<char>>& board, int row, int col, char c) {
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == c) return false; // row
        if (board[i][col] == c) return false; // col
        if (board[3 * (row/3) + i/3][3 * (col/3) + i%3] == c) return false; // box
    }
    return true;
}
      bool backtrack(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char k = '1'; k <= '9'; k++) {
                        if (isValid(board, i, j, k)) {
                            board[i][j] = k;
                            if (backtrack(board)) return true; // solved
                            board[i][j] = '.';
                        }
                    }
                    return false; // no valid digit
                }
            }
        }
        return true; // fully filled
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
       backtrack(board);
    }
};