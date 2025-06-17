class Solution {
public:
    bool isValid(string s) {
        stack<int> stk;

        for (int i = 0; i < s.length(); i++) {
            switch(s[i]) {
                case '(':
                    stk.push(1);
                    break;
                case '[':
                    stk.push(2);
                    break;
                case '{':
                    stk.push(3);
                    break;
                case ')':
                    if (stk.empty() || stk.top() != 1) {
                        return false;
                    }
                    stk.pop();
                    break;
                case ']':
                    if (stk.empty() || stk.top() != 2) {
                        return false;
                    }
                    stk.pop();
                    break;
                case '}':
                    if (stk.empty() || stk.top() != 3) {
                        return false;
                    }
                    stk.pop();
                    break;
            }
        }
        return stk.empty();
    }
};
