class Solution {
public:
    int hammingWeight(int n) {
        int ones = 0;
        while (n > 0) {
            if (n%2 == 1) {
                ones++;
            }
            n /= 2;
        }
        return ones;
    }
};
