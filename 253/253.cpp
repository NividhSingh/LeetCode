class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int current = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        int maxNeeded = -1;
        sort(intervals.begin(), intervals.end());

        for (int i = 0; i < intervals.size(); i++) {
            while (!pq.empty() && pq.top() <= intervals[i][0]) {
                pq.pop();
                current--;
            }
            pq.push(intervals[i][1]);
            current++;
            if (current > maxNeeded) {
                maxNeeded = current;
            }
        }
        return maxNeeded;

    }
};
