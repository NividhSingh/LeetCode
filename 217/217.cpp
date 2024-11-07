class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> n;
        int s = nums.size();
        for (auto i : nums) {
            if (n.count(i) > 0) {
                return true;
            }
            n.insert(i);
        }
        return false;
    }
};
