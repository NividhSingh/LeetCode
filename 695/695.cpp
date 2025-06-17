class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    maxArea = max(maxArea, searchIsland(grid, i, j));
                }
            }
        }
        return maxArea;
    }

    int searchIsland(vector<vector<int>>& grid, int i, int j) {
        stack<int> istk;
        stack<int> jstk;
        istk.push(i);
        jstk.push(j);
        int count = 0;
        while (!istk.empty()) {
            i = istk.top();
            j = jstk.top();
            if (grid[i][j] == 1) {
                count++;
            }
            istk.pop();
            jstk.pop();
            grid[i][j] = 0;

            //Up
            if (i > 0 && grid[i-1][j] == 1) {
                istk.push(i-1);
                jstk.push(j);
            }
            
            //Down
            if (i < grid.size() - 1 && grid[i+1][j] == 1) {
                istk.push(i+1);
                jstk.push(j);
            }

            //Right
            if (j > 0 && grid[i][j-1] == 1) {
                istk.push(i);
                jstk.push(j-1);
            }

            //Left
            if (j < grid[0].size() - 1 && grid[i][j+1] == 1) {
                istk.push(i);
                jstk.push(j+1);
            }

        }
        return count;
    }
};
