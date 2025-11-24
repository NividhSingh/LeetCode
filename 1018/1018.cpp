class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans(nums.size());
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum *= 2;
            sum += nums[i];
            ans[i] =  (sum % 5 == 0);
            sum %= 5;
        }
        return ans;
    }
};
