class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        for (int i = 0; i < n; i++) {
            int a = i;
            int b= 0;
            vector<int> diag;
            while (a < n) {
                diag.push_back(grid[a][b]);
                a++;
                b++;
            }
            sort(diag.begin(), diag.end(), greater<int>());
            a = i;
            b = 0;
            while (a < n) {
                grid[a][b] = diag[b];
                a++;
                b++;
            }
        }

        
        for (int i = 1; i < n; i++) {
            int a = i;
            int b= 0;
            vector<int> diag;
            while (a < n) {
                diag.push_back(grid[b][a]);
                a++;
                b++;
            }
            sort(diag.begin(), diag.end());
            a = i;
            b = 0;
            while (a < n) {
                grid[b][a] = diag[b];
                a++;
                b++;
            }
        }
        return grid;
    }
};
