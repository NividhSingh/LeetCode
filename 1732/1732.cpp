class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int greatest_alt = 0;
        int alt = 0;
        for (int i = 0; i < gain.size(); i++) {
            alt += gain[i];
            greatest_alt = max(alt, greatest_alt);
        }
        return greatest_alt;
    }
};
