class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        sort(nums.begin(), nums.end());
        if (nums[nums.size() - 1] != nums[nums.size() - 2]) {
            return nums[nums.size() - 1];
        }
        for (int i = nums.size() - 2; i >= 1; --i) {
            if (nums[i] != nums[i + 1] && nums[i] != nums[i - 1]) {
                return nums[i];
            }
        }
        if (nums[0] != nums[1]) {
            return nums[0];
        }
        return -1;
    }
};
