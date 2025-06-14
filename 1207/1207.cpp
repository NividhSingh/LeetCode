class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_set<int> vals;
        map<int, int> count;
        for (int i = 0; i < arr.size(); i++) {
            if (vals.find(arr[i]) == vals.end()) {
                count[arr[i]] = 1;
                vals.insert(arr[i]);
            }
            else {
                count[arr[i]]++;
            }
        }
        
        unordered_set<int> occurances;
        for (const auto& item : count) {
            // std::cout << "Key: " << item.first << ", Value: " << item.second << std::endl;
            if(occurances.find(item.second) == occurances.end()) {
                occurances.insert(item.second);
            }
            else {
                return false;
            }

        }
        return true;
    }
};
