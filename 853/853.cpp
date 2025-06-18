class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<int> indeces(speed.size());
        for (int i = 0; i < speed.size(); i++) {
            indeces[i] = i;
        }
        sort(indeces.begin(), indeces.end(), [&](int i1, int i2) {
            return position[i1] > position[i2];
        });
        
        vector<int> positionSorted(position.size());
        vector<int> speedSorted(speed.size());

        for (int i = 0; i < speed.size(); i++) {
            positionSorted[i] = position[indeces[i]];
            speedSorted[i] = speed[indeces[i]];
            // cout << positionSorted[i] << " " << speedSorted[i] << endl;
        }


        float lastTime = (target - positionSorted[0]) * 1.00 / speedSorted[0];

        int fleets = 1;

        // cout << "TImes" << endl;
        for (int i = 1; i < speed.size(); i++) {
            float newTime = (target - positionSorted[i]) * 1.00 / speedSorted[i];

            // cout << lastTime << " " << newTime << endl;
            if (newTime > lastTime) {
                fleets++;
                lastTime = newTime;
            }
        }
        return fleets;
    }
};
