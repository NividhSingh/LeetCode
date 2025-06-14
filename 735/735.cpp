class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;
        for (int i = 0; i < asteroids.size(); i++) {
            if (asteroids[i] > 0) {
                stk.push(asteroids[i]);
            }
            else {
                bool destroyed = false;
                while(!stk.empty() && asteroids[i] * -1 >= stk.top() && stk.top() > 0) {
                    if (asteroids[i] * -1 == stk.top()) {
                        stk.pop();
                        destroyed = true;
                        break;
                    }
                    else {
                        stk.pop();
                    }
                }
                if ((stk.empty() || stk.top() < 0)&& !destroyed) {
                    stk.push(asteroids[i]);
                }
            }
        }
        vector<int> vec (stk.size()); 

        for (int i = vec.size() - 1; i >= 0; i--) {
            vec[i] = stk.top();
            stk.pop();
        }

        return vec;
    }
};
