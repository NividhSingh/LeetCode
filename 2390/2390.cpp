class Solution {
public:
    string removeStars(string s) {
        string s2 = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '*') {
                s2 += s[i];
            }
            else {
                s2.pop_back();
            }
        }
        return s2;
    }
};
