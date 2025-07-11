class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> a;
        vector<bool> b(nums.size());
        for (int i = 0; i < b.size(); i++) {
            b[i] = false;
        }
        vector<int> c;
        perm(a, b, c, nums);
        return a;
    }

    void perm(vector<vector<int>>& a, vector<bool>& b, vector<int> c, vector<int>& nums) {
        if (c.size() == b.size()) {
            a.push_back(c);
            return;
        }
        for (int i = 0; i < b.size(); i++) {
            if (!b[i]) {
                c.push_back(nums[i]);
                b[i] = true;
                perm(a, b, c, nums);
                c.pop_back();
                b[i] = false;
            }
        }
    }
};
