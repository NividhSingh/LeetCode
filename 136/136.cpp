class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> s;
        for (auto num: nums) {
            if (s.find(num) == s.end()) {
                s.insert(num);
            }
            else {
                s.erase(num);
            }
        }
        return *(s.begin());
    }
};
