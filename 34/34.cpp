class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return {-1, -1};
        }
        int l = 0;
        int r = nums.size() - 1;
        int m = (l + r) / 2;
        while (l < r && nums[m] != target) {
            if (nums[m] < target) {
                l = m + 1;
            }
            else {
                r = m - 1;
            }
            m = (l + r) / 2;
        }

        if (nums[m] != target) {
            return {-1, -1};
        }
        l = m; r = m;
        while (l >= 0 && nums[l] == target) {
            --l;
        }
        ++l;
        while (r < nums.size() && nums[r] == target) {
            ++r;
        }
        --r;
        return {l, r};
        
        
    }
};
