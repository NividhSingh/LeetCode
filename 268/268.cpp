class Solution {
public:
    int missingNumber(vector<int>& nums) {
        bool found[nums.size() + 1];
        for (int i = 0; i < nums.size() + 1; i++) {
            found[i] = false;
        }
        for (auto num: nums) {
            found[num] = true;
        }
        for (int i = 0; i < nums.size() + 1; i++) {
            if (!found[i]) {
                return i;
            }
        }
        return -1;
    }
};
