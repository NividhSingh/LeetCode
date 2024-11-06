class RecentCounter {
private:
    int counter;                   // Declare counter as a private member variable
    std::queue<int> pings;  
public:
    RecentCounter() {
        counter = 0;
    }
    
    int ping(int t) {
        pings.push(t);
        counter++;
        while (pings.front() < t - 3000) {
            pings.pop();
            counter --;
        }
        return counter;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
