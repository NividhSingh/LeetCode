class Solution {
public:
    string pushDominoes(string dominoes) {
        char lastValue = 'L';
        int lastIndex = -1;

        for (int i = 0; i < dominoes.length(); i++) {
            if (dominoes[i] == '.'){
                continue;
            }
            if (lastValue == dominoes[i]) {
                for (int j = lastIndex+1; j < i + 1; j++) {
                    dominoes[j] = lastValue;
                }
                lastValue = dominoes[i];
                lastIndex = i;
            }
            else if (lastValue == 'R' && dominoes[i] == 'L') {
                for (int j = lastIndex + 1; j <  (int)((i + lastIndex + 1) / 2); j++) {
                    dominoes[j] = 'R';
                }
                for (int j = (lastIndex+i+2) / 2; j < i; j++) {
                    dominoes[j] = 'L';
                }
                lastValue = dominoes[i];
                lastIndex = i;
            }
            else{
                lastValue = dominoes[i];
                lastIndex = i;
            }
        }
        if (lastValue == 'R') {
            for (int j = lastIndex + 1; j < dominoes.length(); j++) {
                dominoes[j] = 'R';
            }
        }

    return dominoes;
    }
};
