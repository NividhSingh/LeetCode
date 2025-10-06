class Solution {
public:

    struct Compare {
        bool operator()(const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0]; // min-heap based on first element
        }
    };

    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<vector<int>, vector<vector<int>>, Compare> pq;
        int n = grid.size();
        pq.push({grid[0][0], 0, 0});
        int maxWater = max(grid[0][0], grid[n - 1][n - 1]);
        grid[0][0] = -1;
        unordered_set<long> s;
        // unordered_set<vector<int>> s;
        // s.insert({0, 0});
        s.insert(0);
        while (pq.top()[1] != n - 1 || pq.top()[2] != n - 1) {
            int i = pq.top()[1];
            int j = pq.top()[2];
            int topLevel = pq.top()[0];
            pq.pop();
            maxWater = max(maxWater, topLevel);
            if (i > 0 && s.find(n * (i - 1) + j) == s.end()) {
                s.insert((i - 1) * n + j);
                pq.push({grid[i - 1][j], i - 1, j});
            }
            if (i < n - 1 && s.find(n * (i + 1) + j) == s.end()) {
                s.insert((i + 1) * n + j);
                pq.push({grid[i + 1][j], i + 1, j});
            }
            if (j < n - 1 && s.find(n * i + j + 1) == s.end()) {
                s.insert(n * i + j + 1);
                pq.push({grid[i][j + 1], i, j + 1});
            }
            if (j > 0 && s.find(n * i + j - 1) == s.end()) {
                s.insert(n * i + j - 1);
                pq.push({grid[i][j - 1], i, j - 1});
            }
        }
        return maxWater;
        // maxWater = max(maxWater, grid[grid.size() - 1], grid[grid.size() - 1]);
    }
};
