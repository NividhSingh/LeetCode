/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        priority_queue<int, vector<int>, greater<int>> pqAdd;
        priority_queue<int, vector<int>, greater<int>> pqMin;
        vector<Interval> ans;
        int count = 0;
        for (int i = 0; i < schedule.size(); i++) {
            for (int j = 0; j < schedule[i].size(); j++) {
                pqAdd.push(schedule[i][j].start);
                pqMin.push(schedule[i][j].end);
            }
        }

        while (!pqAdd.empty() && !pqMin.empty()) {
            if (pqAdd.top() < pqMin.top()) {
                pqAdd.pop();
                count++;
            }
            else {
                count--;
                int current = pqMin.top();
                if (count == 0 && !pqAdd.empty() && current != pqAdd.top()) {
                    Interval *nInt = new Interval(current, pqAdd.top());
                    ans.push_back(*nInt);
                }
                pqMin.pop();
            }
        }
        return ans;
    }
};
