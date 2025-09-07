class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closest = -1;
        int su = -1;
        for (int i = 0; i < nums.size() - 2; i++) {
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                if (abs(nums[i] + nums[j] + nums[k] - target) < closest || closest == -1) {
                    closest = abs(nums[i] + nums[j] + nums[k] - target);
                    su = nums[i] + nums[j] + nums[k];
                }
                if (closest == 0) {
                    return target;
                }
                if (nums[i] + nums[j] + nums[k] - target <= 0) {
                    j++;
                }
                else {
                    k--;
                }
            }
        }
        return su;
    }
};
