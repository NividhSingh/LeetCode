class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int best[26];
        for (int i = 0; i < 26; i++) {
            best[i] = i;
        }

        int l = s1.length();
        for (int i = 0; i < l; i++) {
            int current1 = (int)(s1[i] - 'a');
            int current2 = (int)(s2[i] - 'a');

            while (best[current1] != current1) {
                best[current1] = best[best[current1]];
                current1 = best[current1];
                
            }
            while (best[current2] != current2) {
                best[current2] = best[best[current2]];
                current2 = best[current2];
            }

            best[current1] = min(current1, current2);
            best[current2] = min(current1, current2);
        }

        for (int i = 0; i < baseStr.length(); i++) {
            int currentLetter = (int)(baseStr[i] - 'a');
            while (currentLetter != best[currentLetter]) {
                best[currentLetter] = best[best[currentLetter]];
                currentLetter = best[currentLetter];
            }
            baseStr[i] = currentLetter + 'a';
        }

        return baseStr;
    }
};
