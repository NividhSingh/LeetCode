class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> v;
        for (int i = 0; i < words.size(); i++) {
            if (found(words[i], x)) {
                v.push_back(i);
            }
        }
        return v;
    }
    bool found(string word, char a) {
        for (int i = 0; i < word.length(); i++) {
            if (word[i] == a) {
                return true;
            }
        }
        return false;
    }
};
