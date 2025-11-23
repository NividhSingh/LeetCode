class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int mod2Count = 0;
        int mod1Count = 0;
        int mod2small = -1;
        int mod2big = -1;
        int mod1small = -1;
        int mod1big = -1;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 3 == 0) {
                sum += nums[i];
            }
            else if (nums[i] % 3 == 1) {
                mod1Count++;
                if (nums[i] < mod1small || mod1small == -1) {
                    mod1big = mod1small;
                    mod1small = nums[i];
                }
                else if (nums[i] < mod1big || mod1big == -1) {
                    mod1big = nums[i];
                }
                sum += nums[i];
            }
            else {
                mod2Count++;
                if (nums[i] < mod2small || mod2small == -1) {
                    mod2big = mod2small;
                    mod2small = nums[i];
                }
                else if (nums[i] < mod2big || mod2big == -1) {
                    mod2big = nums[i];
                }
                sum += nums[i];
            }
        }
        if (sum % 3 == 0) {
            return sum;
        }
        else if (sum % 3 == 1) {
            int option1 = -1;
            int option2 = -1;
            if (mod1Count >= 1) {
                option1 = sum - mod1small;
            }
            if (mod2Count >= 2) {
                option2 = sum - mod2small - mod2big;
            }
            else {
                return max(0, option1);
            }
            return max(option1, option2);
        }
        int option1 = -1;
        int option2 = -1;
        if (mod2Count >= 1) {
            option1 = sum - mod2small;
        }
        if (mod1Count >= 2) {
            option2 = sum - mod1small - mod1big;
        }
        else {
            return max(0, option1);
        }
        return max(option1, option2);
    }
};
