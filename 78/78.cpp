class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> r;

        int n = nums.size();
        int subset_count = static_cast<int>(pow(2, n));

        for (int i = 0; i < subset_count; i++) {
            vector<int> r_sub;
            for (int j = 0; j < n; j++) {
                int bit = (i / static_cast<int>(pow(2, j))) % 2;
                if (bit == 1) {
                    r_sub.push_back(nums[j]);
                } 
            }
            r.push_back(r_sub);
        }
        return r;
    }
};
