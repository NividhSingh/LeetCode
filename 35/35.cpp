class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0 || nums[0] > target) {
            return 0;
        }
        int l = 0;
        int r = nums.size() - 1;
        int m = (l + r) / 2;
        while (l <= r) {
            if (nums[m] == target) {
                return m;
            }
            else if (nums[m] < target) {
                l = m + 1;
            }
            else {
                r = m - 1;
            }
            m = (l + r) / 2;
        }
        return r + 1;
    }
};
