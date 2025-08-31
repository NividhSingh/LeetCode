class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> num1V(num1.length());
        vector<int> num2V(num2.length());

        for (int i = num1.length() - 1; i >= 0; --i) {
            num1V[num1.length() - i - 1] = num1[i] - '0';
        }

        
        for (int i = num2.length() - 1; i >= 0; --i) {
            num2V[num2.length() - i - 1] = num2[i] - '0';
        }

        vector<vector<int>> num1M(10);
        num1M[0] = {0};
        num1M[1] = num1V;
        for (int i = 2; i < 10; i++) {
            vector<int> newV;
            int index = 0;
            int carry = 0;
            while (carry != 0 || index < num1M[i - 1].size()) {
                int newDigit = carry;
                if (index < num1M[i - 1].size()) {
                    newDigit += num1M[i - 1][index];
                }
                if (index < num1V.size()) {
                    newDigit += num1V[index];
                }
                carry = newDigit / 10;
                newDigit = newDigit % 10;
                newV.push_back(newDigit);
                ++index;
            }
            num1M[i] = newV;
        }

        vector<int> ans = {0};

        for (int i2 = 0; i2 < num2V.size(); i2++) {
            int newIndex = i2;
            for (int i1 = 0; i1 < num1M[num2V[i2]].size(); i1++) {
                if (newIndex >= ans.size()) {
                    ans.push_back(0);
                }
                ans[newIndex] += num1M[num2V[i2]][i1];
                newIndex++;
            }
        }
        int carry = 0;
        string ansS = "";
        for (int i = 0; i < ans.size(); i++) {
            ans[i] += carry;
            carry = ans[i] / 10;
            ans[i] = ans[i] % 10;
            ansS.insert(0, 1, ans[i] + '0');
        }

        while (carry > 0) {
            ansS.insert(0, 1, carry % 10 + '0');
            carry /= 10;
        }

        while (ansS.length() > 1 && ansS[0] == '0') {
            ansS.erase(0, 1);
        }
        return ansS;

        
    }
};
