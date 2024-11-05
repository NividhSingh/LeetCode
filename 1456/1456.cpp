class Solution {
public:
    int isVowel(char c) {
    switch (c) {
        case 'a': case 'e': case 'i': case 'o': case 'u':
            return 1;
        default:
            return 0;
        }
    }
    int maxVowels(string s, int k) {
        int max_vowels = 0;
        int vowels = 0;
        int i;
        for (i = 0; i < k; i++) {
            vowels += isVowel(s[i]);
        }
        max_vowels = vowels;
        int si = s.size();
        for (;i < si; i++) {
            vowels += isVowel(s[i]) - isVowel(s[i-k]);
            max_vowels = max(max_vowels, vowels);
        }
        return max_vowels;
    
    }
};
