class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool cols[matrix.size()];
        for (int i = 0; i < matrix.size(); i++) {
            cols[i] = false;
        }
        bool rows[matrix[0].size()];
        for (int i = 0; i < matrix[0].size(); i++) {
            rows[i] = false;
        }

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    rows[j] = true;
                    cols[i] = true;
                }
            }
        }

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (rows[j] || cols[i]) {
                    matrix[i][j] = 0;
                }
            }
        }

        
        
    }
};
