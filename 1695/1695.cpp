class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int left = 0;
        int right = 1;
        unordered_set<int> a;
        int max_sum = nums[0];
        int sum = nums[0];
        a.insert(nums[0]);
        while (right < nums.size()) {
            if (a.find(nums[right]) != a.end()) {
                while (nums[left] != nums[right]) {
                    sum -= nums[left];
                    a.erase(nums[left]);
                    left++;
                }
                left++;
                right++;
            }
            else {
                a.insert(nums[right]);
                sum += nums[right];
                right++;
                max_sum = max(max_sum, sum);
            }
        }
        return max_sum;
    }
};
