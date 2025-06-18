class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> vBig(nums.size() / 3);
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i += 3) {
            vBig[i/3] = {nums[i], nums[i+1], nums[i+2]};
            if (vBig[i/3][2] - vBig[i/3][0] > k) {
                return {};
            }
        }
        return vBig;
    }
};
