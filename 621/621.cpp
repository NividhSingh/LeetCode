class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> m;
        for (auto task: tasks) {
            if (m.find(task) == m.end()) {
                m[task] = 1;
            }
            else {
                m[task]++;
            }
        }
        int max_task_amount = 0;
        int count = 0;
        for (map<char, int>::iterator it = m.begin(); it != m.end(); ++it) {
            if (max_task_amount == it->second) {
                count++;
            }
            if (it->second > max_task_amount) {
                count = 1;
                max_task_amount = it->second;
            }
        }
        max_task_amount = max_task_amount * (n+1) - max(0, 1+n-count);

        if (max_task_amount > tasks.size()) {
            return max_task_amount;
        }
        return tasks.size();
    }
};
