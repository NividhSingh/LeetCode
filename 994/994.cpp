class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<int> istk; 
        queue<int> jstk; 
        int c = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    c++;
                }
                else if (grid[i][j] == 2) {
                    istk.push(i);
                    jstk.push(j);
                    c++;
                }
            }
        }
        if (c == 0) {
            return 0;
        }
        int turns = -1;
        while(!istk.empty()) {
            turns++;
            int stkSize = istk.size();
            for (int k = 0; k < stkSize; k++) {
                c--;
                int i = istk.front();
                int j = jstk.front();
                istk.pop();
                jstk.pop();
                if (i > 0) {
                    if (grid[i - 1][j] == 1) {
                        istk.push(i-1);
                        jstk.push(j);
                        grid[i - 1][j] = 2;
                    }
                }
                if (j > 0) {
                    if (grid[i][j - 1] == 1) {
                        istk.push(i);
                        jstk.push(j-1);
                        grid[i][j - 1] = 2;
                    }
                }
                if (i < grid.size() - 1) {
                    if (grid[i + 1][j] == 1) {
                        istk.push(i + 1);
                        jstk.push(j);
                        grid[i + 1][j] = 2;
                    }
                }
                if (j < grid[0].size() - 1) {
                    if (grid[i][j + 1] == 1) {
                        istk.push(i);
                        jstk.push(j+1);
                        grid[i][j + 1] = 2;
                    }
                }
            }
        }
        if (c != 0) {
            return -1;
        }
        return turns;
    }
};
