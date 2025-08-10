class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string str_n = std::to_string(n);
        int length = str_n.length();

        //find the smallest power of 2 of the same length
        long long number = 1;
        while(number < std::pow(10, length - 1)) {
            number *= 2;
        }

        //make a table
        vector<int> table1 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};//size 10

        //check original
        for(int i=0; i<length; ++i) {
            table1[str_n[i] - '0']++;
        }

        for(int i=0; i<4; ++i) {
            vector<int> table2 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};//size 10
            

            string str_number = std::to_string(number);
            for(int j=0; j<length; ++j) {
                table2[str_number[j] - '0']++;
            }
            
            bool matched = true;
            for(int j=0; j<10 && matched; ++j) {
                if(table1[j] != table2[j]) {
                    matched = false;
                }
            }

            if(matched) {
                return true;
            }

            number *= 2;
        }

    return false;
    }
};
