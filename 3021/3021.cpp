class Solution {
public:
    long long flowerGame(int n, int m) {
            long long a1 = (n + 1) / 2;
            long long a2 = m / 2;
            long long ans = a1 * a2;
            a1 = (m + 1)  / 2;
            a2 = n / 2;
            ans += a1 * a2;
            return ans;
    }
};
