class Solution {
public:
    int countOddLetters(int n) {
        int count[26];
        for (int i = 0; i < 26; i++) {
            count[i] = 0;
        }
        while (n > 0) {
            int d = n % 10;
            n /= 10;
            switch(d) {
                case 0:
                    count['z' - 'a']++;
                    count['e' - 'a']++;
                    count['r' - 'a']++;
                    count['o' - 'a']++;
                    break;
                case 1:
                    count['o' - 'a']++;
                    count['n' - 'a']++;
                    count['e' - 'a']++;
                    break;
                case 2:
                    count['t' - 'a']++;
                    count['w' - 'a']++;
                    count['o' - 'a']++;
                    break;
                case 3:
                    count['t' - 'a']++;
                    count['h' - 'a']++;
                    count['r' - 'a']++;
                    count['e' - 'a'] += 2;
                    break;
                case 4:
                    count['f' - 'a']++;
                    count['o' - 'a']++;
                    count['u' - 'a']++;
                    count['r' - 'a']++;
                    break;
                case 5:
                    count['f' - 'a']++;
                    count['i' - 'a']++;
                    count['v' - 'a']++;
                    count['e' - 'a']++;
                    break;
                case 6:
                    count['s' - 'a']++;
                    count['i' - 'a']++;
                    count['x' - 'a']++;
                    break;
                case 7:
                    count['s' - 'a']++;
                    count['e' - 'a']++;
                    count['v' - 'a']++;
                    count['e' - 'a']++;
                    count['n' - 'a']++;
                    break;
                case 8:
                    count['e' - 'a']++;
                    count['i' - 'a']++;
                    count['g' - 'a']++;
                    count['h' - 'a']++;
                    count['t' - 'a']++;
                    break;
                case 9:
                    count['n' - 'a'] += 2;
                    count['i' - 'a']++;
                    count['e' - 'a']++;
                    break;
            }
        }
        int c = 0;
        for (int i = 0; i < 26; i++) {
            cout << (char)(i + 'a') << " " << count[i] << endl;
            if (count[i] % 2 == 1 ) {
                c += 1;
            }
        }
        return c;
    }
};
