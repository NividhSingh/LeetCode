class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0;
        int count = 0;
        unordered_set<int> s;
        while (index < nums.size()) {
            if (s.find(nums[index]) != s.end()) {
                nums.erase(nums.begin()+index);
            }else {
                count++;
                s.insert(nums[index]);
                index++;
            }
        }
        return count;
    }
};
