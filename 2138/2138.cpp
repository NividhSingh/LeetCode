class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> v;
        for (int i = 0; i < s.length(); i += k) {
            string s2 = s.substr(i, k);
            for (int i = s2.length(); i < k; i++) {
                s2 += fill;
            }
            v.push_back(s2);
        }
        return v;
    }
};
