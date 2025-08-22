class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }
        if (nums.size() == 3) {
            return max(max(nums[0], nums[1]), nums[2]);
        }
        int backThree = 0;
        int backTwo = nums[1];
        int backOne = nums[2];
        for (int i = 3; i < nums.size(); i++) {
            int t = max(backOne, max(backTwo, backThree) + nums[i]);
            backThree = backTwo;
            backTwo = backOne;
            backOne = t;
        }

        int maxP1 = max(backOne, backTwo);


        backThree = nums[0];
        backTwo = nums[1];
        backOne = nums[2];
        if (nums.size() > 3) {
            backOne += backThree;
        }
        for (int i = 3; i < nums.size() - 1; i++) {
            int t = max(backOne, max(backTwo, backThree) + nums[i]);
            backThree = backTwo;
            backTwo = backOne;
            backOne = t;
        }

        int maxP2 = max(backOne, backTwo);
        return max(maxP1, maxP2);
        
    }
};
