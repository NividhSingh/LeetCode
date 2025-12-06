class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<bool> found(nums.size() + 1, false);
        for (auto num : nums) {
            found[num] = true;
        }
        vector<int> ans;
        for (int i = 1; i < nums.size() + 1; i++) {
            if (!found[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
