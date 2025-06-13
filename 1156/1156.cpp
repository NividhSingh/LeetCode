class Solution {
public:
    int maxRepOpt1(string text) {
        vector<int> lengths;
        vector<int> chars;
        int counts[26];
        for (int i = 0; i < 26; i++) {
            counts[i] = 0;
        }
        for (int i = 0; i < text.length(); i++) {
            int n = 1;
            int c = (int)(text[i] - 'a');
            chars.push_back(c);
            while (i < text.length() && text[i] == text[i+1]) {
                i++;
                n++;
            }
            lengths.push_back(n);
            counts[c]++;
        }
        int maxL = 1;
        for (int i = 0; i < chars.size(); i++) {
            if (counts[chars[i]] > 1) {
                maxL = max(maxL, lengths[i] + 1);
            }
            else {
                maxL = max(maxL, lengths[i]);
            }
            if (i + 2 < chars.size()){
                if (chars[i] == chars[i+2] && lengths[i+1] == 1) {
                    if (counts[chars[i]] > 2) {
                        maxL = max(maxL, lengths[i] + lengths[i+2] + 1);
                    }
                    else {
                        maxL = max(maxL, lengths[i] + lengths[i+2]);
                    }
                }
            }
        }
        return maxL;
    }
};
