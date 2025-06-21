class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> tMap;
        map<char, int> sMap;
        for (int i = 0; i < t.length(); i++) {
            if (tMap.find(t[i]) == tMap.end()) {
                tMap[t[i]] = 1;
            }
            else {
                tMap[t[i]]++;
            }
        }
        int bestLeft = -1;
        int bestRight = -1;
        int best = s.length()+1;
        int left = 0;
        int right = -1;

        for (map<char, int>::iterator it = tMap.begin(); it != tMap.end(); ++it) {
            if (sMap.find(it->first) == sMap.end()) {
                sMap[it->first] = 0;
            }
            while (sMap[it->first] < tMap[it->first]) {
                if (right == s.length()) {
                    return "";
                }
                right++;
                if (sMap.find(s[right]) == sMap.end()) {
                    sMap[s[right]] = 1;
                }
                else {
                    sMap[s[right]]++;
                }
            }
        }
        bestLeft = left;
        best = right - left + 1;
        while (right < s.length()) {
            char leftChar = s[left];
            left++;
            sMap[leftChar]--;
            while (sMap[leftChar] < tMap[leftChar]) {
                right++;
                if (right == s.length()) {
                    return s.substr(bestLeft, best);
                }
                if (sMap.find(s[right]) == sMap.end()) {
                    sMap[s[right]] = 1;
                }
                else {
                    sMap[s[right]]++;
                }
            }
            if (right - left + 1 < best) {
                bestLeft = left;
                best = right - left + 1;
            }
        }
        return s.substr(bestLeft, best);
    }
};
