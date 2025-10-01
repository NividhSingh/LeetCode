class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0;
        int empty = 0;
        int full = numBottles;
        while (full > 0) {
            ans += full;
            full += empty;
            empty = full %  numExchange;
            full /= numExchange;
            // numBottles /= numExchange;
        }
        return ans;
    }
};
