class Solution {
public:
    int totalMoney(int n) {
        int monday = 1;
        int ans = 0;
        while (n >= 7) {
            ans += (monday + monday + 6) * 7 / 2;
            n -= 7;
            monday += 1;
        }
        ans += (monday + monday + n - 1) * n / 2;
        return ans;

    }
};

// 1 2 3 4 5 6 7 2 3 4 5 6 7
