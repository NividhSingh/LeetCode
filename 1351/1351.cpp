class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int right_limit = grid[0].size();
        int row = 0;
        int elements = 0;
        while (row < grid.size()) {
            for (int i = 0; i < right_limit; i++) {
                if (grid[row][i] < 0) {
                    elements += (right_limit - i) * (grid.size() - row);
                    right_limit = i;
                    break;
                }
            }

            row++;
        }
        return elements;
    }
};
