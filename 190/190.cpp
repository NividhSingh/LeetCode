class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t newN = 0;
        for (int i = 0; i < 32; i++) {
            newN *= 2;
            newN += n % 2;
            n /= 2;
        }
        
        return newN;
    }
};
