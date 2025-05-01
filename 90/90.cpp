class Solution {
public:
    void add(vector<vector<int>>& r, vector<int>& current, map<int, int> m, vector<int> v, int index) {
        if (index >= v.size()) {
            r.push_back(current);
            return;
        }
        add(r, current, m, v, index + 1);
        for (int i = 0; i < m[v[index]]; i++) {
            current.push_back(v[index]);
            add(r, current, m, v, index + 1);
        }
        for (int i = 0; i < m[v[index]]; i++) {
            current.pop_back();
        }
        return;
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> r;

        int n = nums.size();

        map<int, int> m;
        unordered_set<int> s;
        vector<int> v;

        for (int i = 0; i < n; i++) {
            if (s.count(nums[i])) {
                m[nums[i]]++;
            } else {
                m[nums[i]] = 1;
                s.insert(nums[i]);
                v.push_back(nums[i]);
            }
        }
        vector<int> current;
        add(r, current, m, v, 0);
        return r;
    }
};
