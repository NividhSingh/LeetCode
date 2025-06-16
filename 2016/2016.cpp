class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int bestDifference = -1;
        int minI = nums[0];
        // int maxJ = nums[0] - 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < minI) {
                minI = nums[i];
            }
            if (nums[i] > minI && nums[i] - minI > bestDifference) {

                bestDifference = nums[i] - minI;
            }
        }
        return bestDifference;
    }
};
