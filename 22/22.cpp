class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        string s = "";
        gP2(s, 0, n, v);
        return v;
    }
    void gP2(string s, int open, int need_to_open, vector<string>& v) {
        if (need_to_open == 0 && open == 0) {
            v.push_back(s);
            return;
        }
        if (need_to_open > 0) {
            // s += "(";
            gP2(s + "(", open + 1, need_to_open - 1, v);
            // s.pop();
        }
        if (open > 0) {
            // s += ")";
            gP2(s + ")", open - 1, need_to_open, v);
            // s.pop();
        }
        return;
    }
};
