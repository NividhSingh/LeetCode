class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool numbers[10];
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 10; j++) {
                numbers[j] = false;
            }
            for (int j = 0; j < 9; j++) {
                char letter = board[i][j];
                if (letter == '.') {
                    continue;
                }
                int n = letter - '0';
                
                if(numbers[n]) {
                    cout << i << endl;
                    return false;
                }
                else {
                    numbers[n] = true;
                }
            }

            for (int j = 0; j < 10; j++) {
                numbers[j] = false;
            }
            for (int j = 0; j < 9; j++) {
                char letter = board[j][i];
                if (letter == '.') {
                    continue;
                }
                int n = letter - '0';
                if(numbers[n]) {
                    cout << "j" << endl;
                    cout << j << endl;
                    cout << n << endl;
                    return false;
                }
                else {
                    numbers[n] = true;
                }
            }
            
        }

        for (int i = 0; i < 9; i += 3) {
            for (int k = 0; k < 9; k += 3) {
                for (int j = 0; j < 10; j++) {
                    numbers[j] = false;
                }
                for (int a = 0; a < 3; a++) {
                    for (int b = 0; b < 3; b++) {
                        char letter = board[i+a][k+b];
                        if (letter == '.') {
                            continue;
                        }
                        int n = letter - '0';
                        if(numbers[n]) {
                            return false;
                        }
                        else {
                            numbers[n] = true;
                        }
                    }
                } 
            }
        }
    return true;
    }
};
