class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int low = prices[0];
        int high = prices[0];
        int profit = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (low > prices[i]) 
                low = prices[i];
            if (profit < prices[i] - low) {
                profit = prices[i] - low;
            }
        }
        return profit;
    }
};
