class Solution {
public:

    int solve(string s, string t, int s1, int t1, map<vector<int>, int>& m) {
        if (t.length() - t1 > s.length() - s1) {
            return 0;
        }
        if (t1 == t.length()) {
            return 1;
        }
        if (s1 == s.length()) {
            return 0;
        }
        if (m.find({s1, t1}) != m.end()) {
            return m[{s1, t1}];
        }
        if (s[s1] == t[t1]) {
            if (m.find({s1 + 1, t1 + 1}) == m.end()) {
                m[{s1 + 1, t1 + 1}] = solve(s, t, s1 + 1, t1 + 1, m);
            }
            if (m.find({s1 + 1, t1}) == m.end()) {
                m[{s1 + 1, t1}] = solve(s, t, s1 + 1, t1, m);
            }
            return m[{s1 + 1, t1 + 1}] + m[{s1 + 1, t1}];
        }
        if (m.find({s1 + 1, t1}) == m.end()) {
            m[{s1 + 1, t1}] = solve(s, t, s1 + 1, t1, m);
        }
        return m[{s1 + 1, t1}];

    }

    int numDistinct(string s, string t) {
        map<vector<int>, int> m;
        return solve(s, t, 0, 0, m);
    }
};
