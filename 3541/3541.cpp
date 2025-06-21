class Solution {
public:
    int maxFreqSum(string s) {
        int freq[26];
        for (int i = 0; i < 26; i++) {
            freq[i] = 0;
        }
        for (int i = 0; i < s.length(); i++) {
            freq[s[i] - 'a']++;
        }
        vector<int> vowels = {'a' - 'a', 'e' - 'a', 'i' - 'a', 'o' - 'a', 'u' - 'a'};
        vector<int> consonents = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'};
        int maxVowel = freq[0];
        for (int i = 1; i < 5; i++) {
            maxVowel = max(maxVowel, freq[vowels[i]]);
        }
        int maxC = freq[1];
        for (int i = 1; i < 21; i++) {
            maxC = max(maxC, freq[consonents[i] - 'a']);
        }
        return maxC + maxVowel;
    }
};
