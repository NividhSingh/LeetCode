class Solution {
public:
    int differenceOfSums(int n, int m) {
        int a = n / m;
        return n * (n+1) / 2 -  (m + m * a) * a;
    }
};
