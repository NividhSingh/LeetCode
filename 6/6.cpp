class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        int m = numRows + numRows - 2;
        string newS = "";
        for (int i = 0; i <= m / 2; i++) {
            int j = i; int k = m - i;
            for (int j = i; j < s.length(); j += m) {
                newS += s[j];
                if (k != m / 2 && i != 0 && k < s.length()) {
                    newS += s[k];
                    k += m;
                }
            }
        }
        return newS;
    }
};
