class Solution {
public:

    bool search(vector<vector<char>>& board, vector<vector<bool>>& visited, string word, int index, int i, int j) {
        if (index == word.length()) {
            return true;
        }
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) {
            return false;
        }
        if (board[i][j] != word[index] || visited[i][j]) {
            return false;
        }
        visited[i][j] = true;
        bool a = search(board, visited, word, index + 1, i + 1, j) || search(board, visited, word, index + 1, i - 1, j) ||
                search(board, visited, word, index + 1, i, j - 1) || search(board, visited, word, index + 1, i, j + 1);
        visited[i][j] = false;
        return a;
    }

    bool exist(vector<vector<char>>& board, string word) {
         vector<vector<bool>> boardVisited(board.size());
         for (int i = 0; i < board.size(); i++) {
            vector<bool> row(board[0].size());

            for (int j = 0; j < board[0].size(); j++) {
                row[j] = false;
            }
            boardVisited[i] = row;
         }
         for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (search(board, boardVisited, word, 0, i, j)) {
                    return true;
                }
            }
         }
         return false;

    }
};
