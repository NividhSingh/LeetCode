class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> v(nums.size());
        int a = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < pivot) {
                v[a] = nums[i];
                a++;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == pivot) {
                v[a] = nums[i];
                a++;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > pivot) {
                v[a] = nums[i];
                a++;
            }
        }
        return v;
    }
};
