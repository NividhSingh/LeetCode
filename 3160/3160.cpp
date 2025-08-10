class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        map<int, int> count;
        map<int, int> colors;
        int c = 0;
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            int position = queries[i][0];
            int newColor = queries[i][1];
            if (colors.find(position) == colors.end()) {
                colors[position] = newColor;
            }
            else {
                count[colors[position]]--;
                if (count[colors[position]] == 0) {
                    c--;
                }
                colors[position] = newColor;
            }

            
            if (count.find(newColor) == count.end() || count[newColor] == 0) {
                count[newColor] = 1;
                c++;
            }
            else {
                count[newColor]++;
            }
            ans[i] = c;
        }
        return ans;
    }
};
