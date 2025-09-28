class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        map<int, int> found;
        // vector<bool> found(value, false);
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] < 0) {
                nums[i] += value + ((int)((nums[i] * -1) / value)) * value;
            }
            if (found.find(nums[i] % value) == found.end()) {
                found[nums[i] % value] = 1;
            }
            else {
                found[nums[i] % value]++;
            }
        }
        int minCount = nums.size() + 1;
        int minAtCount = -1;

        for (int i = 0; i < value; i++) {
            if (found.find(i) == found.end()) {
                return i;
            }
            else if (minCount > found[i]) {
                minCount = found[i];
                minAtCount = i;
            }
        }
        return minCount * value + minAtCount;

        for (const auto& pair : found) {
            if (pair.second < minCount ) {
                minCount = pair.second;
                minAtCount = pair.first;
            }
            else if (pair.second == minCount && minAtCount > pair.first) {
                minAtCount = pair.first;
            }
            std::cout << pair.first << ": " << pair.second << std::endl;
        }

        for (int i = 0; i < value; i++) {
            if (found[i] < minCount ) {
                minCount = found[i];
                minAtCount = i;
            }
        }
        return minCount * value + minAtCount;
    }
};
