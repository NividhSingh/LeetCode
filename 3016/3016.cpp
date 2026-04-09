class Solution {
public:
    int minimumPushes(string word) {
        vector<int> count(26,0);
        for (int i = 0; i < word.length(); i++) {
            count[word[i] - 'a']++;
        }
        sort(count.begin(), count.end(), std::greater<>());
        
        int total = 0;

        for (int i = 0; i < 26; i++) {
            total += count[i] * (i/8 + 1);
        }
        return total;
        
        //sort(numbers.begin(), numbers.end(), std::greater<>
    }   
};
