class Solution {
public:
    int countOdds(int low, int high) {
        int dif = high - low;
        if (dif % 2 == 0) {
            if (low % 2 == 0) {
                return dif / 2;
            }
            return dif / 2 + 1;
        }
        else {
            return (dif + 1) / 2;
        }
    }
};
