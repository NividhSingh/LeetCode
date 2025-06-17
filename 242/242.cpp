class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        map<char, int> sm;
        map<char, int> tm;
        for (int i = 0; i < s.length(); i++) {
            if (sm.find(s[i]) == sm.end()) {
                sm[s[i]] = 0;
            }
            sm[s[i]]++;

            if (tm.find(t[i]) == tm.end()) {
                tm[t[i]] = 0;
            }
            tm[t[i]]++;
        }

        for (map<char, int>::iterator it = sm.begin(); it!= sm.end(); ++it) {
            if (it->second != tm[it->first]) {
                return false;
            }
        }
        return true;
    }
};
