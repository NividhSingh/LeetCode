class Solution {
public:
    vector<int> minOperations(string boxes) {
        int r_count = 0;
        int r_steps = 0;
        int l_steps = 0;
        int l_count = 0;
        for (int i = 1; i < boxes.length(); i++) {
            if (boxes[i] == '1') {
                r_count++;
                r_steps += i;
            }
        }
        vector<int> v(boxes.size());
        for (int i = 0; i < boxes.length() - 1; i++) {
            // cout << l_count << " "  << l_steps << " " << i << " " << r_count << " " << r_steps << endl;
            v[i] = l_steps + r_steps;
            r_steps -= r_count;
            if (boxes[i] == '1') {
                l_count++;
            }
            l_steps += l_count;
            if (boxes[i+1] == '1') {
                r_count--;
            }
        }
        // cout << l_count << " "  << l_steps << " " << v.size() - 1 << " " << r_count << " " << r_steps << endl;
        v[v.size() - 1] = l_steps + r_steps;
        return v;
    }
};
