class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int first = 0;
        int last = nums.size()-1;
        // int amount_to_pop = 0;
        while (first <= last) {
            if (nums[first] == val) {
                int temp = nums[first];
                nums[first] = nums[last];
                nums[last] = temp;
                last--;
                // amount_to_pop++;
            }
            else {
                first++;
            }
        }
        return last+1;
    }
};
