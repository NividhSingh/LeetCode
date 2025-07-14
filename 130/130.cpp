class Solution {
public:
    void solve(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            if (board[i][0] == 'O') {
                changeNearBoarder(board, i, 0);
            }
            if (board[i][board[0].size() - 1] == 'O') {
                changeNearBoarder(board, i, board[0].size() - 1);
            }
        }
        for (int j = 0; j < board[0].size(); j++) {
            if (board[0][j] == 'O') {
                changeNearBoarder(board, 0, j);
            }
            if (board[board.size() - 1][j] == 'O') {
                changeNearBoarder(board, board.size() - 1, j);
            }
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'D') {
                    board[i][j] = 'O';
                }
            }
        }
    }

    void changeNearBoarder(vector<vector<char>>& board, int i, int j) {
        stack<pair<int, int>> stck;

        stck.push({i, j});
        board[i][j] = 'D';
        while (stck.size() > 0) {
            i = stck.top().first;
            j = stck.top().second;
            stck.pop();
            if (i > 0 && board[i - 1][j] == 'O') {
                board[i - 1][j] = 'D';
                stck.push({i - 1, j});
            }
            if (j > 0 && board[i][j - 1] == 'O') {
                board[i][j - 1] = 'D';
                stck.push({i, j - 1});
            }
            if (i < board.size() - 1 && board[i + 1][j] == 'O') {
                board[i + 1][j] = 'D';
                stck.push({i + 1, j});
            }
            if (j < board[0].size() - 1 && board[i][j + 1] == 'O') {
                board[i][j + 1] = 'D';
                stck.push({i, j+1});
            }
        }
    }
    

};
