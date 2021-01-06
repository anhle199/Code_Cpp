    bool checkRow(vector<vector<char>>& board, const int &row) {
        vector<bool> check(9, false);
        int index;
        
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == '.')
                continue;
            
            index = board[row][i] - '0';
            if (check[index] == false)
                check[index] = true;
            else
                return false;
        }
        
        return true;
    }
    
    bool checkColumn(vector<vector<char>>& board, const int &col) {
        vector<bool> check(9, false);
        int index;
        
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == '.')
                continue;
            
            index = board[i][col] - '0';
            if (check[index] == false)
                check[index] = true;
            else
                return false;
        }
        
        return true;
    }
    
    bool checkSubBox(vector<vector<char>>& board, const int &row, const int &col) {
        vector<bool> check(9, false);
        int index;
        
        for (int i = row; i < row + 3; i++) {
            for (int j = col; j < col + 3; j++) {
                if (board[i][j] == '.')
                    continue;
                
                index = board[i][j] - '0';
                if (check[index] == false)
                    check[index] = true;
                else
                    return false;
            }
        }
        
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (checkColumn(board, j) == false)
                    return false;
                if (i % 3 == 0 && j % 3 == 0)
                    if (checkSubBox(board, i, j) == false)
                        return false;
            }
            
            if (checkRow(board, i) == false)
                return false;
        }
        
        return true;
    }