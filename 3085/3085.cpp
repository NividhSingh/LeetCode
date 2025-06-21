class Solution {
public:
    int minimumDeletions(string word, int k) {
        int freq[26];
        for (int i = 0; i < 26; i++) {
            freq[i] = 0;
        }
        for (int i = 0; i < word.length(); i++) {
            freq[word[i] - 'a']++;
        }
        int minFreq = word.length();
        for (int i = 0; i < 26; i++) {
            if (0 < freq[i] && freq[i] < minFreq) {
                minFreq = freq[i];
            }
        }
        sort(freq, freq + 26);
        int preSum = 0;
        int best = word.length();
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) {
                continue;
            }
            int m = freq[i] + k;
            int miniSum = 0;
            for (int j = i; j < 26; j++) {
                if (freq[j] > m) {
                    miniSum += freq[j] - m;
                }
            }
            best = min(preSum + miniSum, best);
            preSum += freq[i];
        }
        return best;
      
        
    }
};
