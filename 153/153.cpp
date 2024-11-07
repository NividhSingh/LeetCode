class Solution {
public:
    int findMin(vector<int>& nums) {
        int mid = nums.size() / 2;
        int l = 0;
        int r = nums.size() - 1;
        while (l != r) {
            //cout << l << " " << r << "  " << mid << endl;
            if (nums[l] < nums[r]) {
                return nums[l];
            }
            else if (nums[mid] > nums[l]) {
                l = mid;
                mid = (l + r) / 2;
            }
            else {
                r = mid;
                mid = (r + l) / 2;
            }
            if (r - l == 1) return nums[r];
        }
        return nums[l];
    }
};
