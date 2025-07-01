class Solution {
public:
    int possibleStringCount(string word) {
        int i = 1, c = 0;
        while (i < word.length()) {
            if (word[i] == word[i - 1]) {
                while (i < word.length() && word[i] == word[i - 1]) {
                    i++;
                    c++;
                }
            }
            else {
                i++;
            }
        }
        return c + 1;
    }
};
