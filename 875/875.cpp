class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int minPossible = 1 - 1;
        int maxPossible = 0;
        for (int i = 0; i < piles.size(); i++) {
            maxPossible = max(maxPossible, piles[i]);
        }
        int minWorks = maxPossible;
        int maxDoesntWork = minPossible;
        while (minWorks - maxDoesntWork > 1) {
            int i = (minWorks + maxDoesntWork) / 2;
            if (checkK(piles, h, i)) {
                minWorks = i;
            }
            else {
                maxDoesntWork = i;
            }
        }
        return minWorks;

    }

    bool checkK(vector<int>& piles, int h, int k) {
        int hNeeded = 0;
        for (int i = 0; i < piles.size(); i++) {
            hNeeded += ceil(static_cast<double>(piles[i]) / k);
            if (hNeeded > h) {
                return false;
            }
        }
        return hNeeded <= h;
    }
};
