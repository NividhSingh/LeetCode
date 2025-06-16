class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = nums.size() - 1;
        int ops = 0;
        while (i < j) {
            // cout << i << " " << j << " " << nums[i] + nums[j] << " " << k << endl;
            if (nums[i] + nums[j] == k) {
                i++;
                j--;
                ops++;
            }
            else if (nums[i] + nums[j] < k) {
                i++;
            }
            else {
                j--;
            }
        }
        return ops;
    }
};
