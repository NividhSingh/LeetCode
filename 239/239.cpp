class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<int> pq;
        priority_queue<int> toRemove;
        for (int i = 0; i < k; i++) {
            pq.push(nums[i]);
        }
        vector<int> v;
        v.push_back(pq.top());
        for (int i = k; i < nums.size(); i++) {
            pq.push(nums[i]);
            // cout << i - k << " " << nums[i - k] << endl;
            toRemove.push(nums[i - k]);
            while (!toRemove.empty() && toRemove.top() == pq.top()) {
                toRemove.pop();
                pq.pop();
            }
            v.push_back(pq.top());
        }
        return v;
    }
};
