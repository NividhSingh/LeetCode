class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;//(matrix.size() * matrix[0].size());

        int topBoundry = 0;
        int bottomBoundry = matrix.size() - 1;
        int leftBoundry = 0;
        int rightBoundry = matrix[0].size() - 1;

        while (topBoundry <= bottomBoundry && leftBoundry <= rightBoundry) {
            for (int i = leftBoundry; i <= rightBoundry; i++) {
                //cout << i << " " << matrix[topBoundry][i] << endl;
                v.push_back(matrix[topBoundry][i]);
            }
            topBoundry++;
            //cout << endl;
            if (topBoundry > bottomBoundry) {
                break;
            }
            for (int i = topBoundry; i <= bottomBoundry; i++) {
                //cout << i << " "  << matrix[i][rightBoundry] << endl;
                v.push_back(matrix[i][rightBoundry]);
            }
            rightBoundry--;
            //cout << endl;
            if (rightBoundry < leftBoundry) {
                break;
            }
            for (int i = rightBoundry; i >= leftBoundry; i--) {
                //cout << i << " "  << matrix[bottomBoundry][i] <<  endl;
                v.push_back(matrix[bottomBoundry][i]);
            }
            if (topBoundry > bottomBoundry) {
                break;
            }
            bottomBoundry--;
            //cout << endl;
            for (int i = bottomBoundry; i >= topBoundry; i--) {
                //cout << i << " " << matrix[i][leftBoundry] << endl;
                v.push_back(matrix[i][leftBoundry]);
            }
            leftBoundry++;
            //cout << endl;
        }


        return v;
    }
};
