class Solution {
public:
    int search(vector<int>& nums, int target) {
        int r = nums.size() - 1;
        int l = 0;
        int m = (l + r) / 2;
        while (l <= r) {
            if (nums[m] == target) return m;
            if ((nums[l] <= nums[m])) {
                if (nums[l] <= target && target <= nums[m])
                    r = m - 1;
                
                else {
                    l = m + 1;
                }
            }
            else {
                if (nums[m] <= target && target <= nums[r])
                    l = m + 1;
                else {
                    r = m - 1;
                }
            }
            m = (l + r) / 2;
        }
        return -1;
    }
};
