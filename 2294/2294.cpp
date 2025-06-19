class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int partitions = 1;
        int least = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - k > least) {
                partitions++;
                least = nums[i];
            }
        }
        return partitions;
    }
};
