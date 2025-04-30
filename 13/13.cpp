#include <map>

class Solution {
public:
    int romanToInt(string s) {
        std::map<char,int> symbolToInteger {
            { 'I', 1 },
            { 'V', 5 },
            { 'X', 10 },
            { 'L', 50 },
            { 'C', 100 },
            { 'D', 500 },
            { 'M', 1000 }
        };
        int sum = 0;
        for (int i = 0; i < s.length() - 1; i++) {
            if (symbolToInteger[s[i]] < symbolToInteger[s[i + 1]]) {
                sum -= symbolToInteger[s[i]];
            }
            else {
                sum += symbolToInteger[s[i]];
            }
        }
        sum += symbolToInteger[s[s.length() - 1]];

        return sum;
    }
};
