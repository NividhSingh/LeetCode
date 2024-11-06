class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        int i = 0;
        int first_sum = 0;
        while (i < nums.size()) {
            first_sum += nums[i];
            sum += nums[i];
            if (sum == first_sum * 2) 
                return i;
            sum -= nums[i];
            i++;
        }
        return -1;
    }
};
