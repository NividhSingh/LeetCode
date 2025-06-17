class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        for (auto num: nums) {
            if (m.find(num) == m.end()) {
                m[num] = 1;
            }
            else {
                m[num]++;
            }
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        for(map<int, int>::iterator it = m.begin(); it != m.end(); ++it) {
            pq.push(it->second);
        }
        while (pq.size() > k) {
            pq.pop();
        }
        vector<int> v;
        for(map<int, int>::iterator it = m.begin(); it != m.end(); ++it) {
            if (it->second >= pq.top()) {
                v.push_back(it->first);
            }
        }
        return v;
    }
};
