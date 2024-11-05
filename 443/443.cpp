class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 1;
        int j = 1;
        char current_char = chars[0];
        int count = 1;
        while (i < chars.size()) {
            
            if (chars[i] != chars[i-1]) {
                if (count > 1) {
                    int m = count;
                    int digits = 0;
                    while (m > 0) {
                        digits++;
                        m /= 10;
                    }
                    while (digits > 0) {
                        // Separate last digit from
                        // the number and add ASCII
                        // value of character '0' is 48
                        chars[j] = static_cast<char>((count / static_cast<int>(pow(10, digits-1))) + 48);
                
                        // Truncate the last
                        // digit from the number
                        count = count % static_cast<int>(pow(10, digits - 1));
                        j++;
                        digits--;
                    }
                }
                chars[j] = chars[i];
                j++;
                count = 1;

            }
            else {
                count++;
            }
            i++;
        }
        if (count > 1) {
                    int m = count;
                    int digits = 0;
                    while (m > 0) {
                        digits++;
                        m /= 10;
                    }
                    while (digits > 0) {
                        // Separate last digit from
                        // the number and add ASCII
                        // value of character '0' is 48
                        chars[j] = static_cast<char>((count / static_cast<int>(pow(10, digits-1))) + 48);
                
                        // Truncate the last
                        // digit from the number
                        count = count % static_cast<int>(pow(10, digits - 1));
                        j++;
                        digits--;
                    }
                }
        return j;
    }
};
