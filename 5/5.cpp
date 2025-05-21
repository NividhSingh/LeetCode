class Solution {
public:
    string longestPalindrome(string s) {
        int longest = 0;
        int center = 0;
        for (int i = 0; i < s.length(); i++) {
            int length = 1;
            while (i - length >= 0 && i + length <= s.length()-1 && s[i-length] == s[i+length]) {
                length++;
            }
            if (length > longest) {
                longest = length;
                center = i;
            }
        }

        int evenLongest = 0;

        int evenmax = 0;
        int evenstart =0;
        for (int i = 0; i < s.length() - 1; i++) {
            int below = i;
            int above = i + 1;
            int length = 0;
            while (below >= 0 && above <= s.length() - 1 && s[below] == s[above]) {
                length += 2;
                below--;
                above++;
            }
            if (length > evenmax) {
                evenmax = length;
                evenstart = below + 1;
            }
        }
        if (evenmax > longest*2 - 1) {
            return s.substr(evenstart, evenmax);
        }
        return s.substr(center - longest + 1, longest * 2 - 1);
    }
};
