class Solution {
public:
    int calculateTime(string keyboard, string word) {
        int m[26];
        for (int i = 0; i < keyboard.length(); i++) {
            m[keyboard[i] - 'a'] = i;
        }
        int distance = m[word[0] - 'a'];
        for (int i = 1; i < word.length(); i++) {
            distance += abs(m[word[i] - 'a'] - m[word[i - 1] - 'a']);
        }
        return distance;
    }
};
