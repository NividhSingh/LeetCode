class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<bool> found(nums.size(), false);
        int d = 0;
        for (auto num : nums) {
            if(found[num - 1]) {
                d = num - 1;
                found[num  - 1] = true;
            }
            found[num  - 1] = true;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!found[i]) {
                return {d + 1, i + 1};
            }
        }
        return {0, 0};
    }
};
