class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> a;
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            if (s.find(nums[i]) == s.end()) {
                s.insert(nums[i]);
            }
            else {
                a.push_back(nums[i]);
                if (a.size() == 2) {
                    return a;
                }
            }
        }
        return a;
    }
};
