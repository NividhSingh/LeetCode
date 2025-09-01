class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        for (auto str: strs) {
            string str_copy = str;
            sort(str_copy.begin(), str_copy.end());
            ans.push_back({str_copy, str});
        }
        sort(ans.begin(), ans.end());
        vector<vector<string>> actualAns;
        actualAns.push_back({ans[0][1]});

        for (int index = 1; index < ans.size(); ++index) {
            if (ans[index][0] == ans[index - 1][0]) {
                actualAns[actualAns.size() - 1].push_back(ans[index][1]);
            }
            else {
                actualAns.push_back({ans[index][1]});
            }
        }
        return actualAns;
    }
};
