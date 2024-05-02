class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();

        // check if row is valid
        for(int i = 0; i < row; i++){
            set<char> s;
            for(int j = 0; j < col; j++){
                if(board[i][j] != '.' && s.count(board[i][j]) == 0){
                    s.insert(board[i][j]);
                }else if(board[i][j] != '.' && s.count(board[i][j]) > 0){
                    return false;
                }
            }
        }

        // check if col is valid
        for(int i = 0; i < col; i++){
            set<char> s;
            for(int j = 0; j < row; j++){
                if(board[j][i] != '.' && s.count(board[j][i]) == 0){
                    s.insert(board[j][i]);
                }else if(board[j][i] != '.' && s.count(board[j][i]) > 0){
                    return false;
                }
            }
        }

        for(int i = 0; i < row; i+=3){
            for(int j = 0; j < col; j+=3){
                set<char> s;
                for(int k = i; k < i + 3; k++){
                    for(int l = j; l < j + 3; l++){
                        if(board[k][l] != '.' && s.count(board[k][l]) == 0){
                            s.insert(board[k][l]);
                        }else if(board[k][l] != '.' && s.count(board[k][l]) == 1){
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};