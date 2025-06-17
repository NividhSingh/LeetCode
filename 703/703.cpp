class KthLargest {
private:
    int k;
    priority_queue<int, std::vector<int>, std::greater<int>> pq;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        // this->pq = new priority_queue<int>;
        for (auto num: nums) {
            add(num);
        }
    }
    
    int add(int val) {
        this->pq.push(val);
        if (pq.size() > this->k) {
            pq.pop();
        }
        return pq.top();
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
