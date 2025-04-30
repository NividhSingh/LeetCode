#include <map>

class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        int position = 0;
        int l = s.length(); 
        while (position < l && s[position] == 'M') {
            sum += 1000;
            position++;
        }
        if (position + 1 < l && s[position + 1] == 'M') {
            sum += 900;
            position += 2;
        }
        while (position < l && s[position] == 'D') {
            sum += 500;
            position++;
        }
        if (position + 1 < l && s[position + 1] == 'D') {
            sum += 400;
            position += 2;
        }
        while (position < l && s[position] == 'C') {
            sum += 100;
            position++;
        }
        if (position + 1 < l && s[position + 1] == 'C') {
            sum += 90;
            position += 2;
        }
        while (position < l && s[position] == 'L') {
            sum += 50;
            position++;
        }
        if (position + 1 < l && s[position + 1] == 'L') {
            sum += 40;
            position += 2;
        }
        while (position < l && s[position] == 'X') {
            sum += 10;
            position++;
        }
        if (position + 1 < l && s[position + 1] == 'X') {
            sum += 9;
            position += 2;
        }
        while (position < l && s[position] == 'V') {
            sum += 5;
            position++;
        }
        if (position + 1 < l && s[position + 1] == 'V') {
            sum += 4;
            position += 2;
        }
        while (position < l && s[position] == 'I') {
            sum += 1;
            position++;
        }
        return sum;
        
        // std::map<char,int> symbolToInteger {
        //     { 'I', 1 },
        //     { 'V', 5 },
        //     { 'X', 10 },
        //     { 'L', 50 },
        //     { 'C', 100 },
        //     { 'D', 500 },
        //     { 'M', 1000 }
        // };
        // int sum = 0;
        // for (int i = 0; i < s.length() - 1; i++) {
        //     if (symbolToInteger[s[i]] < symbolToInteger[s[i + 1]]) {
        //         sum -= symbolToInteger[s[i]];
        //     }
        //     else {
        //         sum += symbolToInteger[s[i]];
        //     }
        // }
        // sum += symbolToInteger[s[s.length() - 1]];

        // return sum;
    }
};
