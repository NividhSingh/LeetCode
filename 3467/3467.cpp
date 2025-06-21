class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int odds = 0;
        for (int i = 0; i < nums.size(); i++) {
            odds += nums[i]%2;
            nums[i] = 0;
        }
        for (int i = nums.size() - 1; i + odds > nums.size() - 1; i--) {
            nums[i] = 1;
        }
        return nums;
    }
};
