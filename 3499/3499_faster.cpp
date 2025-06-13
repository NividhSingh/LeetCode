class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int number_of_ones = 0;
        int max_sum = 0;
        int last_zero = -1;
        
        for (int i = 0; i < s.length();) {
            char value = s[i];
            int n = 0;
            while (i < s.length() && s[i] == value) {
                // cout << "IN" << endl;
                n++;
                i++;
            }

            if (value == '1') {
                number_of_ones += n;
            }
            else {
                if (last_zero != -1) {
                    max_sum = max(last_zero + n, max_sum);
                }
                last_zero = n;
            }
        }
        return number_of_ones + max_sum;
    }
};
