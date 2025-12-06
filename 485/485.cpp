class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0;
        int count = 0;
        for (auto num: nums) {
            if (num == 1) {
                count++;
            }
            else {
                if (count > maxCount) {
                    maxCount = count;
                }
                count = 0;
            }
        }
        if (count > maxCount) {
            return count;
        }
        return maxCount;
    }
};
