class Solution {
public:
    int minPartitions(string n) {
        int m = n[0] - '0';
        for (int i = 1; i < n.length(); i++) {
            m = max(m, n[i] - '0');
        }
        return m;
    }
};
