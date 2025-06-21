class Solution {
public:
    int minProductSum(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int s = 0;

        for (int i = 0; i < nums1.size(); i++) {
            s += nums1[i] * nums2[nums1.size() - 1 - i];
        }
        return s;
    }
};
