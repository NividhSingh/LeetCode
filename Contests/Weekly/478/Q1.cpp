class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        if (k >= nums.size()) {
            return 0;
        }
        if (k == 0) {
            return nums.size();
        }
        sort(nums.begin(), nums.end());
        int m = nums[nums.size() - k];
        int i = nums.size() - k - 1;
        while(i >= 0 && m == nums[i]) {
            i--;
        }
        return i + 1;
    }
};©leetcode
