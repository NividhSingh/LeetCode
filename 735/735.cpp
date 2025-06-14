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
        vector<int> vec; 


        // Convert the stack to a vector
        while (!stk.empty()) {
            vec.push_back(stk.top());
            stk.pop();
        }

    // If you need the order to be the same as the stack's insertion order, you can reverse the vector
    std::reverse(vec.begin(), vec.end());
        return vec;
    }
};
