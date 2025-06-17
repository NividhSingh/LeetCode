class Solution {
public:
    vector<int> partitionLabels(string s) {
        int lowest[26];
        int highest[26];
        for (int i = 0; i < 26; i++) {
            lowest[i] = -1;
            highest[i] = -1;
        }
        for (int i = 0; i < s.length(); i++) {
            int a = s[i] - 'a';
            if (lowest[a] == -1) {
                lowest[a] = i;
            }
            highest[a] = i;
        }
        int last_index = -1;
        vector<int> v;
        int index = 0;
        int max_needed = 0;
        while (index < s.length()) {
            int a = s[index] - 'a';
            max_needed = max(max_needed, highest[a]);
            if (index == max_needed) {
                v.push_back(index - last_index);
                last_index = index;
            }            
            index++;
        }
        return v;
    }
};
