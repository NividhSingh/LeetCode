class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = nums[0];
        int second = numeric_limits<int>::max();
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > second) {
                return true;
            }
            else if (nums[i] > first && nums[i] < second) {
                second = nums[i];
            }
            else if (nums[i] < first) {
                first = nums[i];
            }
        }
        return false;
    }
};
