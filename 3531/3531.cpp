class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        map<int, int> leastRow;
        map<int, int> mostRow;
        map<int, int> leastCol;
        map<int, int> mostCol;
        for (auto building: buildings) {
            if (leastRow.find(building[0]) != leastRow.end()) {
                if (building[1] < leastRow[building[0]]) {
                    leastRow[building[0]] = building[1];
                }
                if (building[1] > mostRow[building[0]]) {
                    mostRow[building[0]] = building[1];
                }
            }
            else {
                leastRow[building[0]] = building[1];
                mostRow[building[0]] = building[1];
            }

            if (leastCol.find(building[1]) != leastCol.end()) {
                if (building[0] < leastCol[building[1]]) {
                    leastCol[building[1]] = building[0];
                }
                if (building[0] > mostCol[building[1]]) {
                    mostCol[building[1]] = building[0];
                }
            }
            else {
                leastCol[building[1]] = building[0];
                mostCol[building[1]] = building[0];
            }
        }
        int count = 0;
        for (auto building: buildings) {
            if (leastRow[building[0]] < building[1] &&
            mostRow[building[0]] > building[1] &&
            leastCol[building[1]] < building[0] &&
            mostCol[building[1]] > building[0]
                ) {
                    count++;
                }
        }
        return count;
    }
};
