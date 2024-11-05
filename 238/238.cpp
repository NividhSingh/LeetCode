class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        bool zero = false;
        for (int i = 0; i < nums.size(); i++) {
            if (!zero && nums[i] == 0) {
                zero = true;
            }
            else{
                product *= nums[i];
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                nums[i] = product;
            }
            else if (zero) {
                nums[i] = 0;
            }
            else {
                nums[i] = product/nums[i];
            }
        }
        return nums;
        
    }
};
