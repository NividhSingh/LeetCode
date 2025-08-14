class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        int d1 = mat.size();
        int d2 = mat[0].size();
        vector<int> indecies(d1);
        for (int i = 1; i < mat.size(); i++) {
            indecies[i] = 0;
        }

        for (int i = 0; i < d2; i++) {
            int m = mat[0][i];
            int working = true;
            for (int j = 1; j < d1 && working; j++) {
                while (indecies[j] < d2 && mat[j][indecies[j]] < m) {
                    indecies[j]++;
                }
                if (mat[j][indecies[j]] > m) {
                    working = false;
                }
                if (indecies[j] == d2) {
                    return -1;
                }
            }
            if (working) {
                return m;
            }
        }
        return -1;
    }
};
