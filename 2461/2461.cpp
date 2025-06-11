class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long current_sum = 0;
        long long best = 0;
        unordered_set<int> found;
        map<int, long long> how_many_currently;
        int invalid = 0;
        for (int i = 0; i < k; i++) {
            if (found.find(nums[i]) != found.end()) {
                how_many_currently[nums[i]] += 1;
                invalid++;
            }
            else {
                found.insert(nums[i]);
                how_many_currently[nums[i]] = 1;
            }
            current_sum += nums[i];
        }
        if(invalid == 0) {
            best = current_sum;
        }

        for (int i = 0; i < nums.size() - k; i++) {
            current_sum -= nums[i];
            current_sum += nums[i+k];
            if (found.find(nums[i+k]) != found.end()) {
                how_many_currently[nums[i+k]] += 1;
                if (how_many_currently[nums[i+k]] > 1){
                    invalid++;
                }
            }
            else {
                found.insert(nums[i+k]);
                how_many_currently[nums[i+k]] = 1;
            }
            if (how_many_currently[nums[i]] > 1) {
                invalid--;
            }
            how_many_currently[nums[i]]--;
            if(invalid == 0 && current_sum > best) {
                best = current_sum;
            }
        }
        return best;

    }
};
