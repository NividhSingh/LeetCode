class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix[0].size();
        int n = matrix.size();
        int low = 0;
        int high = m * n - 1;
        int mid = (low + high) / 2;
        int in = mid / m;
        int im = mid % m;
        while (matrix[in][im] != target) {
            // cout << low << " " << high << " " << mid << endl;
            if (low > high) {
                return false;
            }
            if (matrix[in][im] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
            mid = (low + high) / 2.0;
            in = mid / m;
            im = mid % m;
        }
        return true;
    }
};
