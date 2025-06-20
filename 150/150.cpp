class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (int i = 0; i < tokens.size(); i++) {

            switch(tokens[i][0]) {
                int a, b;
                case '+':
                    a = s.top();
                    s.pop();
                    b = s.top();
                    s.pop();
                    s.push(a + b);
                    break;
                case '/':
                    a = s.top();
                    s.pop();
                    b = s.top();
                    s.pop();
                    s.push(b / a);
                    break;
                case '*':
                    a = s.top();
                    s.pop();
                    b = s.top();
                    s.pop();
                    s.push(a * b);
                    break;
                case '-':
                    if (tokens[i].length() == 1) {
                        a = s.top();
                        s.pop();
                        b = s.top();
                        s.pop();
                        s.push(b - a);
                        break;
                    }
                default:
                    s.push(stoi(tokens[i]));
                    break;
            }
        }
        return s.top();
    }
};
