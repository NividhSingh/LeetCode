class Solution {
public:
    int countTriples(int n) {
        vector<int> sqs;
        for (int i = 1; i <= n; i++) {
            int cubed = i * i;
            sqs.push_back(cubed);
        }
        int count = 0;
        for (int i = 0; i < sqs.size(); i++) {
            for (int j = 0; j < sqs.size(); j++) {
                for (int k = i + 1; k < sqs.size(); k++) {
                    // cout << i << " " << j << " " << k << " ";
                    // cout << sqs[i] << " " << sqs[j] << " " << sqs[k] << endl;
                    if (sqs[i] + sqs[j] == sqs[k]) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};
