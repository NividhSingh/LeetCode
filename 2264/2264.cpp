class Solution {
public:
    string largestGoodInteger(string num) {
        int largest = -1;
        for (int i = 2; i < num.length(); i++) {
            if (num[i] == num[i - 1] && num[i - 1] == num[i - 2] && num[i] - '0' > largest) {
                largest = num[i] - '0';
            }
        }
        if (largest == -1) {
            return "";
        }
        return string(3, largest + '0');
        // return str(a + a + a;
    }
};
