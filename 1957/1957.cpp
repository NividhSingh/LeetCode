class Solution {
public:
    string makeFancyString(string s) {
        if (s.length() <= 2) {
            return s;
        }
        string s2 = "";
        for (int i = 0; i + 2 < s.length(); i++) {
            if (!(s[i] == s[i+1] && s[i] == s[i+2])) {
                s2 += s[i];
            }
        }
        s2 += s[s.length() - 2];
        s2 += s[s.length() - 1];
        return s2;
    }
};
