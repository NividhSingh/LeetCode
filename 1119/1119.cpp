class Solution {
public:
    string removeVowels(string s) {
        string s2 = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i]!= 'a' &&s[i]!= 'u' &&s[i]!= 'o' &&s[i]!= 'i' &&s[i]!= 'e') {
                s2 += s[i];
            }
        }
        return s2;
    }
};
