class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0];
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if  (sum < 0)
                sum = max(0, sum);
            sum += nums[i];
            max_sum = max(sum, max_sum);
        }
        return max_sum;
    }
};
