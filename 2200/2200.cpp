class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == key) {
                int minVal = max(0, i - k);
                int maxVal = i + k;
                if (maxVal > nums.size() - 1) {
                    maxVal = nums.size() - 1;
                }
                for (int j = minVal; j <= maxVal; j++) {
                    s.insert(j);
                }
            }
        }
        vector<int> v;
        for (unordered_set<int>::iterator it = s.begin(); it != s.end(); ++it) {
            v.push_back(*it);
        }
        sort(v.begin(), v.end());
        return v;
    }
};
