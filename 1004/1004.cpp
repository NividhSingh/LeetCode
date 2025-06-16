class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeros_so_far = 0;
        int i = -1;
        int j = 0;
        if (nums[0] == 0) {
            zeros_so_far = 1;
        }
        int maxPossible = 0;
        while (j < nums.size()) {
            // cout << "START: " << i << " " << j << endl;
            while (zeros_so_far > k) {
                i++;
                if (nums[i] == 0) {
                    zeros_so_far--;
                }
            }
            // cout << "AFTER: " << i << " " << j << endl;
            maxPossible = max(maxPossible, j - i);
            j++;
            if (j < nums.size() && nums[j] == 0) {
                zeros_so_far++;
            }
            
        }
        return maxPossible;
    }
};
