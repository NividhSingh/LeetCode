class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.length() < s1.length()) {
            return false;
        }
        vector<int> count1(26, 0);
        vector<int> count2(26, 0);
        for (int i = 0; i < s1.size(); i++) {
            count1[s1[i] - 'a']++;
        }
        for (int j = 0; j< s1.size(); j++) {
            count2[s2[j] - 'a']++;
        }
        int dif = 0;
        for (int i = 0; i < 26; i++) {
            if (count1[i] != count2[i]) {
                dif++;
            }
        }
        if (dif == 0) {
            return true;
        }
        for (int i = s1.size(); i < s2.size(); i++) {
            int old = s2[i - s1.size()] - 'a';
            int newE = s2[i] - 'a';
            if (count1[old] == count2[old]) {
                dif++;
            }
            count2[old]--;
            if (count1[old] == count2[old]) {
                dif--;
            }
            if (count1[newE] == count2[newE]) {
                dif++;
            }
            count2[newE]++;
            if (count1[newE] == count2[newE]) {
                dif--;
            }
            if (dif == 0) {
                return true;
            }
        }
        return false;
    }
    
};
