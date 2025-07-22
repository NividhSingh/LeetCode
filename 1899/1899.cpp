class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool found[3];
        found[0] = false;
        found[1] = false;
        found[2] = false;
        for (int i = 0; i < triplets.size(); i++) {
            if (triplets[i][0] <= target[0] && triplets[i][1] <= target[1] && triplets[i][2] <= target[2]) {
                for (int j = 0; j < 3; j++) {
                    found[j] = found[j] || triplets[i][j] == target[j];
                }
            }
            if (found[0] && found[1] && found[2]) {
                return true;
            }
        }
        return found[0] && found[1] && found[2];
    }
};
