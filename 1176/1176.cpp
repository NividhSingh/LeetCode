class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += calories[i];
        }
        int count = 0;
        if (sum > upper) {
            count++;
        }
        else if (sum < lower) {
            count--;
        }
        for (int i = k; i < calories.size(); i++) {
            sum -= calories[i - k];
            sum += calories[i];
            if (sum > upper) {
                count++;
            }
            else if (sum < lower) {
                count--;
            }
        }
        return count;
    }
};
