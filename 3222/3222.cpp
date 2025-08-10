class Solution {
public:
    string winningPlayer(int x, int y) {
        int maxX = x;
        int maxY = y / 4;
        int minBoth = min(maxX, maxY);
        if (minBoth % 2) {
            return "Alice";
        }
        return "Bob";
    }
};
