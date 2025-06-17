class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        multiset<int> weights;
        for (auto stone: stones) {
            weights.insert(stone);
        }
        while(weights.size() > 1) {
            int newWeight = *(weights.rbegin());
            weights.erase(prev(weights.end()));
            newWeight -= *(weights.rbegin());
            weights.erase(prev(weights.end()));
            if (newWeight > 0) {
                weights.insert(newWeight);
            }
        }
        if (weights.size() == 0) {
            return 0; 
        }
        return *(weights.begin());
        
    }
};
