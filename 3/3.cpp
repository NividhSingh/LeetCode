class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_map<char, int> dictionary;
        int max_substring = 0;
        int i = 0;
        int j = 0;
        while (i < s.length()) {
            if (dictionary.find(s[i]) != dictionary.end() && dictionary[s[i]] >= j) {
                // cout << "1: " << i << " " << j << " " << s[i] << endl;
                // cout << "Found: " << s[i] << " at index: " << dictionary[s[i]] <<std::endl;
                j = dictionary[s[i]] + 1;
                // max_substring = max(max_substring, i - j);
                dictionary[s[i]] = i;
                i++;
            }
            else {
                // cout << "2: " << i << " " << j << " " << s[i] << endl;
                dictionary[s[i]] = i;
                i++;
                max_substring = max(max_substring, i - j);
            }
            
        //for (const auto& pair : dictionary) {
            // cout << "D" << pair.first << ": " << pair.second << "\n";
        //}
        //// cout << "MAX" << max_substring << endl;
        }

        return max_substring;
    }
};
