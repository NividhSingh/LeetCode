class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<bool> val;
        vector<int> lengths;
        int sum = 0;
        for (int i = 0; i < s.length();) {
            int value = s[i] - '0';
            int n = 0;
            while (i < s.length() && s[i] - '0' == value) {
                // cout << "IN" << endl;
                n++;
                i++;
            }
            val.push_back(value == 1);
            lengths.push_back(n);
            sum += value * n;
            // cout << sum << " " << n << " " << value << endl;
        }
        int m = 0;
        for (int i = 0; i + 2 < val.size(); i++) {
            if (!val[i]) {
                m = max(m, lengths[i] + lengths[i+2]);
            }
        }
        sum += m;
        return sum;
    }
};
