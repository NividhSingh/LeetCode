class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> letters;
        vector<int> counts;
        int currentLetter = s[0] - 'A';
        int count = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1]) {
                count++;
            }
            else {
                counts.push_back(count);
                letters.push_back(currentLetter);
                currentLetter = s[i] - 'A';
                count = 1;
            }
        }
        letters.push_back(currentLetter);
        counts.push_back(count);

        int maxCount = counts[0];
        for (int i = 0; i < letters.size(); i++) {
            int letter = letters[i];
            int a = 0;
            int tempI = i;
            int count1 = 0;
            while (tempI < letters.size() && ((letters[tempI] == letter) || (a + counts[tempI] <= k))) {
                count1 += counts[tempI];
                if (letters[tempI] != letter) {
                    a += counts[tempI];
                }
                tempI++;
            }
            count1 += (k - a);
            maxCount = max(maxCount, count1);
        }
        
        if (maxCount > s.length()) {
            return s.length();
        }
        return maxCount;

    }
};
