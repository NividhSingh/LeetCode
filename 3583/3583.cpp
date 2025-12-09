class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        map<int, int> right;
        map<int, int> left;
        for (auto num:nums) {
            if (right.find(num) == right.end()) {
                right[num] = 0;
                left[num] = 0;
            }
            right[num]++;
        }
        long long count = 0;
        for (auto num:nums) {
            right[num]--;
            if (left.find(num * 2) != left.end()) {
                count += modmul(right[num * 2], left[num * 2], 1000000007);
                //(left[num * 2] * right[num * 2]) % (1000000007);
                count = count % (1000000007);
            }
            left[num]++;
        }
        return (int) count;
    }
    int modmul(int a, int b, int M) {
        int sum = 0;
        while (b > 0) {
            if (b % 2 == 1) {
                sum += a;
            }
            a %= 1000000007;
            a *= 2;
            a %= 1000000007;
            b /= 2;
        }
        return sum;
    }
};
