class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> b;
        vector<vector<int>> c;
        combine(candidates, target, 0, c, b, 0);
        return c;
    }

    void combine(vector<int>& candidates, int target, int coin, vector<vector<int>>& a, vector<int> b, int currentSum) {
        if (currentSum > target) {
            return;
        }
        if (currentSum == target) {
            a.push_back(b);
            return;
        }
        if (coin == candidates.size()) {
            return;
        }
        while (currentSum <= target) {
            combine(candidates, target, coin + 1, a, b, currentSum);
            currentSum += candidates[coin];
            b.push_back(candidates[coin]);
        }
    }
};
