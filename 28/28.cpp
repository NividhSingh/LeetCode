class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.length() > haystack.length()) {
            return -1;
        }
        for (int i = 0; i < haystack.length() - needle.length() + 1; i++) {
            int sub = 0;
            for (; sub < needle.length(); sub++) {
                if (needle[sub] != haystack[i + sub]) {
                    break;
                }
            }
            if (sub == needle.length()) {
                return i;
            }
        }
        return -1;
    }
};
