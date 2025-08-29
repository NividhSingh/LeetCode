class Solution {
public:

    // Custom comparator for reverse ordering
    struct Compare {
        bool operator()(const vector<int>& a, const vector<int>& b) const {
            return a > b;  // reversed (normally would be a < b)
        }
    };

    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<vector<int>, vector<vector<int>>, Compare> pq;
    
        pq.push({grid[0][0], 0, 0});
        int min_water = grid[0][0];
        int n = grid.size();
        
        while(!pq.empty()) {
            int new_min_water = pq.top()[0];
            int x = pq.top()[1];
            int y = pq.top()[2];
            pq.pop();

            min_water = max(min_water, new_min_water);

            if (x == n - 1 && y == n - 1) {
                return min_water;
            }
            if (x > 0 && grid[x - 1][y] != -1) {
                pq.push({grid[x - 1][y], x - 1, y});
            }
            if (x < n - 1 && grid[x + 1][y] != -1) {
                pq.push({grid[x + 1][y], x + 1, y});
            }
            if (y > 0 && grid[x][y - 1] != -1) {
                pq.push({grid[x][y - 1], x, y - 1});
            }
            if (y < n - 1 && grid[x][y + 1] != -1) {
                pq.push({grid[x][y + 1], x, y + 1});
            }
            grid[x][y] = -1;
        }
        return -2;
    }
};
