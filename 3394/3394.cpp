class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> a1(rectangles.size());
        for (int i = 0; i < rectangles.size(); i++) {
            a1[i] = {rectangles[i][0], rectangles[i][2]};
        }
        
        vector<vector<int>> a2(rectangles.size());
        for (int i = 0; i < rectangles.size(); i++) {
            a2[i] = {rectangles[i][1], rectangles[i][3]};
        }

        sort(a1.begin(), a1.end());
        sort(a2.begin(), a2.end());

        int c = 0;
        int lastEnding = a1[0][1];
        for (int i = 1; i < a1.size(); i++) {
            if (lastEnding <= a1[i][0]) {
                ++c;
                lastEnding = a1[i][1];
            }
            else {
                lastEnding = max(lastEnding, a1[i][1]);
            }
            if (c == 2) {
                return true;
            }
        }
        
        c = 0;
        lastEnding = a2[0][1];
        for (int i = 1; i < a2.size(); i++) {
            if (lastEnding <= a2[i][0]) {
                ++c;
                lastEnding = a2[i][1];
            }
            else {
                lastEnding = max(lastEnding, a2[i][1]);
            }
            if (c == 2) {
                return true;
            }
        }
        return false;
    }
};
