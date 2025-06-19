class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return x;
        }
        if (n < 0) {
            return 1 / (x * myPow(x, -1 * (n+1)));
        }
        if (n % 2 == 1) {
            double x2 = myPow(x, (n - 1) / 2);
            return x * x2 * x2;
        }
        double x2 = myPow(x, n / 2);
        return x2 * x2;
        
        
    }
};
