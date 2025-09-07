class Solution {
public:
    int lengthOfLastWord(string s) {
        int index = s.length() - 1;
        int count = 0;
        while (index >= 0 && s[index] == ' ') {
            index--;
        }
        for (int i = index; i >= 0; i--) {
            if (s[i] == ' ') {
                return count;
            }
            else {
                count++;
            }
        }
        return count;
    }
};
