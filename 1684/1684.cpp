class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> a;
        for (int i = 0; i < allowed.length(); i++) {
            a.insert(allowed[i]);
        }
        int c = 0;
        for (auto word: words) {
            bool good = true;
            for (int i = 0; i < word.length(); i++) {
                if (a.find(word[i]) == a.end()) {
                    good = false;
                    break;
                }
            }
            if (good)
                c++;
        }
        return c;
    }
};
