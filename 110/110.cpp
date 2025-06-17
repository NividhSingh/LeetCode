class Solution {
public:
    static bool compare(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        int end = -1;
        for (auto interval: intervals) {
            if (interval[0] < end) {
                return false;
            }
            end = interval[1];
        }
        return true;
    }
};
