class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        int backOne = 2;
        int backTwo = 1;
        for (int i = 3; i <= n; i++) {
            int current = backOne + backTwo;
            backTwo = backOne;
            backOne = current;
        }
        return backOne;
    }
};
