class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int c = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                c++;
            }
        }
        return c > nums.size() / 2.0;
    }
};
