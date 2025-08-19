class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        bool num1has0 = false;
        bool num2has0 = false;
        long long minSum1 = 0;
        long long minSum2 = 0;

        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] == 0) {
                num1has0 = true;
                minSum1 += 1;
            }
            minSum1 += nums1[i];
        }

        for (int i = 0; i < nums2.size(); i++) {
            if (nums2[i] == 0) {
                num2has0 = true;
                minSum2 += 1;
            }
            minSum2 += nums2[i];
        }

        if (minSum1 == minSum2) {
            return minSum1;
        }
        if (minSum1 < minSum2) {
            if (num1has0) {
                return minSum2;
            }
            else {
                return -1;
            }
        }
        if (num2has0) {
            return minSum1;
        }
        return -1;
    }
};
