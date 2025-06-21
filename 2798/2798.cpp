class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int c = 0; 
        for (auto hour: hours) {
            if (hour >= target) {
                c++;
            }
        }
        return c;
    }
};
