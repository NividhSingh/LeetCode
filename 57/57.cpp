class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.size() == 0) {
            return {newInterval};
        }
        vector<vector<int>> ans;
        bool added = false;
        for (int i = 0; i < intervals.size(); i++) {
            vector<int> originalInterval = intervals[i];
            if (added || originalInterval[1] < newInterval[0]) { // Original before new
                ans.push_back(originalInterval);
            }
            else if (newInterval[1] < originalInterval[0]) { // New before original
                ans.push_back(newInterval);
                ans.push_back(originalInterval);
                added = true;
            }
            else if (newInterval[1] < originalInterval[1]) {
                ans.push_back({min(originalInterval[0], newInterval[0]), originalInterval[1]});
                added = true;
            }
            else {
                int start = min(originalInterval[0], newInterval[0]);
                while (i < intervals.size() && newInterval[1] > originalInterval[1]) {
                    ++i;
                    if (i < intervals.size()){
                        originalInterval = intervals[i];
                    }
                }
                if (i == intervals.size()) {
                    ans.push_back({start, newInterval[1]});
                    added = true;
                }
                else if (newInterval[1] < originalInterval[0]) {
                    ans.push_back({start, newInterval[1]});
                    ans.push_back(originalInterval);
                    added = true;
                }
                else {
                    added = true;
                    ans.push_back({start, originalInterval[1]});
                }
            }
            
        }
        if (!added) {
            ans.push_back(newInterval);
        }
        return ans;

    }
};
