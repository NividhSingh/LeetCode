class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        int jumps = 0;
        int maxForJumps = 0;
        int maxForNextJumps = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (maxForNextJumps == nums.size() - 1) {
                return jumps + 1;
            }
            if (i > maxForJumps) {
                maxForJumps = maxForNextJumps;
                jumps++;
            }
            maxForNextJumps = max(maxForNextJumps, i + nums[i]);
        }
        return jumps;
    }
};
