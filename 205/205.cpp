class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> m;
        map<char, char> m2;
        for (int i = 0; i < s.length(); i++) {
            if (m.contains(s[i]) && t[i] != m[s[i]]) {
                return false;
            }
            if (m2.contains(t[i]) && s[i] != m2[t[i]]) {
                return false;
            }
            m[s[i]] = t[i];
            m2[t[i]] = s[i];
        }
        return true;
    }
};
