class Solution {
public:
    int maxDifference(string s) {
        int count[26];
        for (int i = 0; i < 26;  i++) {
            count[i] = 0;
        }
        for (int i = 0; i < s.length(); i++) {
            count[(int)(s[i] - 'a')]++;
        }
        int max_odd = -1;
        int min_even = s.length() + 1;
        for (int i = 0; i < 26; i++) {
            if (count[i] == 0) {
                continue;
            }
            if (count[i] % 2 == 0) {
                min_even = min(min_even, count[i]);
            }
            else {
                max_odd = max(max_odd, count[i]);
            }
        }
        return max_odd - min_even;
    }
};
