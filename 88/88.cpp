class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int first = m - 1;
        int second = n - 1;
        int third = m + n - 1;
        while (first >= 0 || second >= 0) {
            if (first >= 0 && (second < 0 || nums1[first] > nums2[second])) {
                nums1[third] = nums1[first];
                first--;
            }
            else {
                nums1[third] = nums2[second];
                second--;
            }
            third--;
        }
        while (first >= 0) {
            nums1[third] = nums1[first];
            first--;
            third--;
        }
        while (second >= 0) {
            nums1[third] = nums2[second];
            second--;
            third--;
        }
    }
};
