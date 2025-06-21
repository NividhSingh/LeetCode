class Solution {
public:
    struct Compare {
        bool operator() (const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0];
        }
    };

    vector<int> dailyTemperatures(vector<int>& temperatures) {
        priority_queue<vector<int>, vector<vector<int>>, Compare> pq;
        vector<int> ans(temperatures.size());
        for (int i = 0; i < temperatures.size(); i++) {
            pq.push({temperatures[i], i});
            int a = pq.top()[0];
            while (!pq.empty() && pq.top()[0] < temperatures[i]) {
                ans[pq.top()[1]] = i - pq.top()[1];
                pq.pop();
            }
        }
        while (!pq.empty()) {
            ans[pq.top()[1]] = 0;
            pq.pop();
        }
        return ans;
    }
};
