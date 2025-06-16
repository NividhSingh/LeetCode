class Solution {
public:
    vector<int> orArray(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            nums[i] = nums[i] | nums[i+1];
        }
        nums.pop_back();
        return nums;
    }
};
