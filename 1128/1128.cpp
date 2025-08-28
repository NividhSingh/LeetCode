class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<int, map<int, int>> m;
        int sum = 0;
        for (auto domino: dominoes) {
            int smal = min(domino[0], domino[1]);
            int big = max(domino[0], domino[1]);
            if (m.find(smal) == m.end()) {
                map<int, int> sm;
                sm[big] = 1;
                m[smal] = sm;
            }
            else {
                // map<int, int> sm = m[smal];
                if (m[smal].find(big) == m[smal].end()) {
                    m[smal][big] = 1;
                }
                else {
                    sum -= m[smal][big] * (m[smal][big] - 1) / 2;
                    m[smal][big]++;
                    sum += m[smal][big] * (m[smal][big] - 1) / 2;
                    
                }
            }
        }
        return sum;
    }
};
