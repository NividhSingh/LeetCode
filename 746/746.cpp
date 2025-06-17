class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> totalCosts(cost.size());
        totalCosts.push_back(0);
        totalCosts.push_back(0);
        for (int i = 2; i < cost.size(); i++) {
            totalCosts[i] = min(totalCosts[i - 1] + cost[i-1], totalCosts[i - 2] + cost[i-2]);
        }
        return min(totalCosts[cost.size() - 1] + cost[cost.size() - 1], totalCosts[cost.size() - 2] + cost[cost.size() - 2]);
    }
};
