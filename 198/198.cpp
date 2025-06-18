class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        else if (nums.size() == 1) {
            return nums[0];
        }
        else if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }
        int bestBackThree = nums[0];
        int bestBackTwo = nums[1];
        int bestBackOne = nums[0] + nums[2];
        for (int i = 3; i < nums.size(); i++) {
            int best = max(bestBackThree, bestBackTwo) + nums[i];
            bestBackThree = bestBackTwo;
            bestBackTwo = bestBackOne;
            bestBackOne = best;
        }
        return max(bestBackOne, bestBackTwo);
    }
};
