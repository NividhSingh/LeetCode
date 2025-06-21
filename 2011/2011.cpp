class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int i = 0;
        for (auto op: operations) {
            if (op[1] == '-') {
                i--;
            }
            else {
                i++;
            }
        }
        return i;
    }
};
