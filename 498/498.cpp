class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;

        bool whichWay = true;
        int m = mat[0].size() - 1; 
        int n = mat.size() - 1;
        for (int i = 0; i <= m + n; i++) {
            if (whichWay) {
                int first = 0;
                int second = i;
                if (second > n) {
                    int dif = second - n;
                    first += dif;
                    second -= dif;
                }
                for(; first <= m && second >= 0; ++first) {
                    ans.push_back(mat[second][first]);
                    --second;
                }
            }
            else {
                int first = i;
                int second = 0;
                if (first > m) {
                    int dif = first - m;
                    second += dif;
                    first -= dif;
                }
                for(; second <= n && first >= 0; ++second) {
                    ans.push_back(mat[second][first]);
                    --first;
                }
                
            }
            whichWay = !whichWay;
        }
        return ans;
    }
};   
