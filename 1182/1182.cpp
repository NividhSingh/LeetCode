class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        vector<int> last = {-1, -1, -1};
        vector<int> leftLast1(colors.size());
        vector<int> leftLast2(colors.size());
        vector<int> leftLast3(colors.size());

        vector<vector<int>> lastLefts = {leftLast1, leftLast2, leftLast3};

        for (int i = 0; i < colors.size(); i++) {
            last[colors[i] - 1] = i;
            for (int j = 0; j < 3; j++) {
                if (last[j] == -1) {
                    lastLefts[j][i] = -1;
                }
                else {
                    lastLefts[j][i] = i - last[j];
                }
            }
        }

        last = {-1, -1, -1};
        for (int i = colors.size() - 1; i >= 0; --i) {
            last[colors[i] - 1] = i;
            for (int j = 0; j < 3; j++) {
                if (last[j] == -1) {
                }
                else {
                    int d = last[j] - i;
                    if (lastLefts[j][i] == -1 || lastLefts[j][i] > d) {
                        lastLefts[j][i] = d;
                    }
                }
            }
        }
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            ans[i] = lastLefts[queries[i][1] - 1][queries[i][0]];
        }
        return ans;
    }
};
