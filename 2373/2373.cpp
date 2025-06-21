class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>> v;
        for (int i = 1; i < grid.size() - 1; i++) {
            vector<int> vSmall;
            for (int j = 1; j < grid[0].size() - 1; j++) {
                int m = max(grid[i][j], max(grid[i-1][j], max(grid[i+1][j], max(grid[i][j-1], max(grid[i+1][j-1], max(grid[i-1][j-1], max(grid[i][j+1], max(grid[i+1][j+1], grid[i-1][j+1]))))))));
                vSmall.push_back(m);
            }
            v.push_back(vSmall);
        }
        return v;
    }
};
