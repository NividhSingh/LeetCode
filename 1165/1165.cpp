class Solution {
public:
    int calculateTime(string keyboard, string word) {
        map<char, int> m;
        for (int i = 0; i < keyboard.length(); i++) {
            m[keyboard[i]] = i;
        }
        int distance = m[word[0]];
        for (int i = 1; i < word.length(); i++) {
            distance += abs(m[word[i]] - m[word[i - 1]]);
        }
        return distance;
    }
};
