class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> arr(m + 1, vector<int>(n + 1));

        // int arr[word1.length() + 1][word2.length() + 1];
        for (int i = 0; i <= m; i++) {
            arr[i][0] = i;
        }
        for (int i = 0; i <= n; i++) {
            arr[0][i] = i;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int m = arr[i - 1][j] + 1;
                m = min(m, arr[i][j - 1] + 1);
                if (word1[i - 1] == word2[j - 1]) {
                    m = min(m, arr[i - 1][j - 1]);
                }
                else {
                    m = min(m, arr[i - 1][j - 1] + 1);
                }
                arr[i][j] = m;
            }
        }
        return arr[m][n];
    }
};
