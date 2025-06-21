class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        vector<vector<bool>> visited(rooms.size());
        queue<vector<int>> toVisit;
        for (int i = 0; i < rooms.size(); i++) {
            vector<bool> v(rooms[0].size());
            for (int j = 0; j < rooms[0].size(); j++) {
                if (rooms[i][j] == 0) {
                    toVisit.push({i, j});
                    v[j] = true;
                }
                else {
                    v[j] = false;
                }
            }
            visited[i] = v;
        }
        int distance = 0;
        vector<vector<int>> changes = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        while (!toVisit.empty()) {
            int n = toVisit.size();
            for (int i = 0; i < n; i++) {
                rooms[toVisit.front()[0]][toVisit.front()[1]] = distance;
                for (int j = 0; j < 4; j++) {
                    int newI = toVisit.front()[0] + changes[j][0];
                    int newJ = toVisit.front()[1] + changes[j][1];
                    if (newI < 0 || newJ < 0 || newI >= rooms.size() || newJ >= rooms[0].size()) {
                        continue;
                    }
                    if (rooms[newI][newJ] == -1 || visited[newI][newJ]) {
                        continue;
                    }
                    visited[newI][newJ] = true;
                    toVisit.push({newI, newJ});
                }
                toVisit.pop();
            }
            distance++;
        }
    }
};
