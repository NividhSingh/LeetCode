class Solution {
public:
    int getFood(vector<vector<char>>& grid) {
        queue<vector<int>> place;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '*') {
                    place.push({i, j});
                    break;
                }
            }
            if (place.size() > 0) {
                break;
            }
        }
        int distance = 0;
        int spotsAtCurrentDistance = place.size();
        while (place.size() > 0) {
            if (place.front()[0] > 0) {
                if (grid[place.front()[0] - 1][place.front()[1]] == '#') {
                    return distance + 1;
                }
                else if (grid[place.front()[0] - 1][place.front()[1]] == 'O') {
                    place.push({place.front()[0] - 1, place.front()[1]});
                    grid[place.front()[0] - 1][place.front()[1]] = 'X';
                }
            }
            if (place.front()[0] < grid.size() - 1) {
                char a = grid[place.front()[0] + 1][place.front()[1]];
                if (grid[place.front()[0] + 1][place.front()[1]] == '#') {
                    return distance + 1;
                }
                else if (grid[place.front()[0] + 1][place.front()[1]] == 'O') {
                    place.push({place.front()[0] + 1, place.front()[1]});
                    grid[place.front()[0] + 1][place.front()[1]] = 'X';
                }
            }
            if (place.front()[1] > 0) {
                if (grid[place.front()[0]][place.front()[1] - 1] == '#') {
                    return distance + 1;
                }
                else if (grid[place.front()[0]][place.front()[1] - 1] == 'O') {
                    place.push({place.front()[0], place.front()[1] - 1});
                    grid[place.front()[0]][place.front()[1] - 1] = 'X';
                }
            }
            if (place.front()[1] < grid[0].size() - 1) {
                if (grid[place.front()[0]][place.front()[1] + 1] == '#') {
                    return distance + 1;
                }
                else if (grid[place.front()[0]][place.front()[1] + 1] == 'O') {
                    place.push({place.front()[0], place.front()[1] + 1});
                    grid[place.front()[0]][place.front()[1] + 1] = 'X';
                }
            }
            spotsAtCurrentDistance--;
            place.pop();
            if (spotsAtCurrentDistance == 0) {
                distance++;
                spotsAtCurrentDistance = place.size();
            }
        }
        return -1;
    }
};
