class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxSoFar = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > maxSoFar) {
                return false;
            }
            maxSoFar = max(maxSoFar, i + nums[i]);
        }
        return true;
    }
};
