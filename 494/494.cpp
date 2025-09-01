class Solution {
public:
    int search(vector<int>& nums, int target, int index) {
        if (index == nums.size()) {
            if (target == 0) {
                return 1;
            }
            else {
                return 0;
            }
        }
        return search(nums, target - nums[index], index + 1) + search(nums, target + nums[index], index + 1);
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return search(nums, target * -1, 0);
    }
};
