class Solution {
public:
    int maxDistinct(string s) {
        vector<int> count(26);
        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;
        }
        int m = 0;
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) {
                m++;
            }
        }
        return m;
    }
};©leetcode
