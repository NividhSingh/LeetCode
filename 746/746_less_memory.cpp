class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int minusOne = 0;
        int minusTwo = 0;
        // vector<int> totalCosts(cost.size());
        // totalCosts.push_back(0);
        // totalCosts.push_back(0);
        for (int i = 2; i < cost.size(); i++) {
            int t= min(minusOne + cost[i - 1], minusTwo + cost[i - 2]);
            minusTwo = minusOne;
            minusOne = t;
            // totalCosts[i] = min(totalCosts[i - 1] + cost[i-1], totalCosts[i - 2] + cost[i-2]);
        }
        return min(minusOne + cost[cost.size() - 1], minusTwo + cost[cost.size() - 2]);
    }
};
