class Solution {
public:
    string filterCharacters(string s, int k) {
        map<char, int> m;
        for (int i = 0; i < s.length(); i++) {
            if (m.find(s[i]) == m.end()) {
                m[s[i]] = 1;
            }
            else {
                m[s[i]]++;
            }
        }
        string ans = "";
        for (int i = 0; i < s.length(); i++) {
            if (m[s[i]] < k) {
                ans += s[i];
            }
        }
        return ans;
    }
};
