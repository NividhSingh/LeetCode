class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> count;
        for (int i = 0; i < arr.size(); i++) {
            if (count.find(arr[i]) == count.end()) {
                count[arr[i]] = 1;
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
