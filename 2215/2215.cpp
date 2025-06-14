class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1;
        unordered_set<int> s2;
        vector<int> v1;
        vector<int> v2;

        for (int i = 0; i < nums1.size(); i++) {
            s1.insert(nums1[i]);
        }
        for (int i = 0; i < nums2.size(); i++) {
            if (s1.find(nums2[i]) == s1.end() && s2.find(nums2[i]) == s2.end()) {
                v1.push_back(nums2[i]);
            }
            s2.insert(nums2[i]);
        }

        unordered_set<int> s3;

        for (int i = 0; i < nums1.size(); i++) {
            if (s3.find(nums1[i]) == s3.end() && s2.find(nums1[i]) == s2.end()) {
                v2.push_back(nums1[i]);
            }
            s3.insert(nums1[i]);
        }

        vector<vector<int>> v3;
        v3.push_back(v2);
        v3.push_back(v1);

        return v3;
        
    }
};
