class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int, vector<int>> m;
        vector<vector<int>> v;
        for (int i = 0; i < groupSizes.size(); i++) {
            if (m.find(groupSizes[i]) == m.end()) {
                m[groupSizes[i]] = {};
            }
            m[groupSizes[i]].push_back(i);
            if (m[groupSizes[i]].size() == groupSizes[i]) {
                v.push_back(m[groupSizes[i]]);
                m[groupSizes[i]] = {};
            }
        }
        return v;
    }
};
