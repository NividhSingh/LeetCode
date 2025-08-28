class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        for (int i = 0; i < dominoes.size(); i++) {
            sort(dominoes[i].begin(), dominoes[i].end());
        }

        sort(dominoes.begin(), dominoes.end());

        int l = dominoes[0][0];
        int r = dominoes[0][1];
        int sum = 0; 
        int c = 1;
        for (int i = 1; i < dominoes.size(); i++) {
            int newL = dominoes[i][0];
            int newR = dominoes[i][1];
            
            if (l == newL && r == newR) {
                ++c;
            }
            else {
                sum += (c * (c - 1)) / 2;
                c = 1;
                l = newL;
                r = newR;
            }
        }
        sum += (c * (c - 1)) / 2;
        return sum;
    }
};
