class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> s;
        for (int i = 0; i < jewels.length(); i++) {
            s.insert(jewels[i]);
        }
        int count = 0;
        for (int j = 0; j < stones.size(); j++) {
            if (s.find(stones[j]) != s.end()) {
                count++;
            }
        }
        return count;
    }
};
