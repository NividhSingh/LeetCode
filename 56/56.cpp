class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        int lastStart = intervals[0][0];
        int lastEnd = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] > lastEnd) {
                ans.push_back({lastStart, lastEnd});
                lastStart = intervals[i][0];
                lastEnd = intervals[i][1];
            }
            else {
                lastEnd = max(lastEnd, intervals[i][1]);
            }
        }
        ans.push_back({lastStart, lastEnd});
        return ans;
    }
};
