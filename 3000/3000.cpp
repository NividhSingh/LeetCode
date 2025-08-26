class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxArea = -1;
        long long maxDiag = -1;
        for (int i = 0; i < dimensions.size(); i++) {
            long long diag = pow(dimensions[i][0], 2) + pow(dimensions[i][1], 2);
            if (diag > maxDiag || (diag == maxDiag && maxArea < dimensions[i][0] * dimensions[i][1])) {
                maxDiag = diag;
                maxArea = dimensions[i][0] * dimensions[i][1];
            }
        }
        return maxArea;
    }
};
