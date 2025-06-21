class Solution {
public:
    int pivotInteger(int n) {
        int s = n * (n + 1) / 2;
        int d = sqrt(s);
        if (d * d == s) {
            return d;
        }
        return -1;
    }
};
