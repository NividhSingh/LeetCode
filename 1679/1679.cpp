class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int, int> m;
        int ops = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (m.find(k-nums[i]) != m.end() && m[k-nums[i]] > 0) {
                m[k-nums[i]]--;
                ops++;
            }
            else {
                if (m.find(nums[i]) != m.end()) {
                    m[nums[i]]++;
                }
                else {
                    m[nums[i]] = 1;
                }
            }
        }
        return ops;
    }
};
