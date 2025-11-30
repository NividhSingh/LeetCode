class Solution {
public:
    bool removeOnes(vector<vector<int>>& grid) {
        if (grid.size() == 1 || grid[0].size() == 1) {
            return true;
        }
        for (int i = 1; i < grid.size(); i++) {
            int dif = (grid[i][0] - grid[i - 1][0] + 2) % 2;

            for (int j = 0; j < grid[0].size(); j++) {
                if ((grid[i][j] - grid[i - 1][j] + 2) % 2 != dif) {
                    return false;
                }
            }
        }
        return true;
    }
};
