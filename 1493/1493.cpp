class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = -1;
        int right = 0;
        int best_so_far = 0;
        int last_zero = -1;
        for (; left < right && right < nums.size(); right++) {
            // cout << left << " " << right << " " << last_zero << endl;
            if (nums[right] == 0) {
                left = last_zero;
                last_zero = right;
            }
            if (best_so_far < right - left - 1) {
                best_so_far = right - left - 1;
            }
        }

        if (best_so_far == nums.size()) {
            best_so_far--;
        }
        return best_so_far;
    }
};
