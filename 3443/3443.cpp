class Solution {
public:
    int maxDistance(string s, int k) {
        int maxDistance = 0;
        int n = 0, sou = 0, e = 0, w = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'N') {
                n++;
            }
            else if (s[i] == 'S') {
                sou++;
            }
            else if (s[i] == 'E') {
                e++;
            }
            else {
                w++;
            }
            int changes = 0;
            if ((n > 0 && sou > 0) || (e > 0 && w > 0)) {
                changes += min(sou, n);
                changes += min(e, w);
                changes = min(k, changes);
                changes *= 2;
            }
            int distance = abs(sou - n) + abs(e - w) + changes;
            maxDistance = max(maxDistance, distance);
        }
        return maxDistance;
    }
};
