class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int index = 0;
        vector<string> stk;
        for (int i = 1; i <= n; i++) {
            if (index == target.size()) {
                return stk;
            }
            if (i < target[index]) {
                stk.push_back("Push");
                stk.push_back("Pop");
            }
            else if (i == target[index]) {
                stk.push_back("Push");
                index++;
            }
        }
        return stk;
    }
};
