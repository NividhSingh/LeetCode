class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        map<int, int> m;
        for (auto c: coins) {
            m[c] = 1; 
        }
        for (int i = 1; i <= amount; i++) {
            if (m.find(i) == m.end()) {
                calculate_change(m, i, coins);
            }
        }
        return m[amount];
    }

    void calculate_change(map<int, int>& m, int val, vector<int>& coins) {
        int minSoFar = -1;
        for (auto i: coins) {
            if (val - i < 0) {
                continue;
            }
            if (m[i] != -1 && m[val - i] != -1) {
                if (minSoFar == -1 || m[i] + m[val - i] < minSoFar) {
                    minSoFar = m[i] + m[val - i];
                }
            }
        }
        m[val] = minSoFar;
    }
};
