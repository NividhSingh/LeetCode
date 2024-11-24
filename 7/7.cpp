class Solution {
public:
    int reverse(int x) {
        int reverseX = 0;

        while (x != 0) {
            cout << reverseX << endl;
            int digit = x % 10;
            // Check for overflow before multiplying by 10
            if (reverseX > INT_MAX / 10 || (reverseX == INT_MAX / 10 && digit > INT_MAX % 10)) {
                return 0; // Overflow detected
            }
            if (reverseX < INT_MIN / 10 || (reverseX == INT_MIN / 10 && digit < INT_MIN % 10)) {
                return 0; // Underflow detected
            }
            reverseX *= 10;
            reverseX += digit;
            x /= 10;
        }
        return (int) reverseX;
    }
};
