class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> v(n+1);
        v[0] = 0;
        int two_so_far = 1;
        while (two_so_far <= n){
            for (int i = 0; i < two_so_far && i + two_so_far <= n; i++) {
                v[i + two_so_far] = v[i] + 1;
            }
            two_so_far *= 2;
        }
        return v;
    }
};
