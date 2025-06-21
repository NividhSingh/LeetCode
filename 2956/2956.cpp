class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1;
        unordered_set<int> s2;
        int c1 = 0; int c2 = 0;
        for (auto num: nums1) {
            s1.insert(num);
        }
        for (auto num: nums2) {
            if (s1.find(num) != s1.end()) {
                c2++;
            }
            s2.insert(num);
        }
        for (auto num: nums1) {
            if (s2.find(num) != s2.end()) {
                c1++;
            }
        }
        return {c1, c2};
    }
};
