class Solution {
 bool isValid(vector<vector<char>>& board, int row, int col, char c) {

    for (int i = 0; i < 9; i++) {
        if (board[row][i] == c) return false;
    }


    for (int i = 0; i < 9; i++) {
        if (board[i][col] == c) return false;
    }

    int boxRow = 3 * (row / 3);   
    int boxCol = 3 * (col / 3);   
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[boxRow + i][boxCol + j] == c) return false;
        }
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
                            if (backtrack(board)) return true; 
                            board[i][j] = '.';
                        }
                    }
                    return false; 
                }
            }
        }
        return true; 
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
       backtrack(board);
    }
};