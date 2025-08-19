class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long c = 0;
        long long current_c = 0;
        for (long long i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                c += (current_c + 1) * current_c / 2;
                current_c = 0;
            }
            else {
                current_c++;
            }
        }
        c += (current_c + 1) * current_c / 2;
        return c;
    }
};
