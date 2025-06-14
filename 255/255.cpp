class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        stack<int> st;
        
        st.push(preorder[0]);

        int upper = preorder[0];
        int lower = -1;
        for (int i = 1; i < preorder.size(); i++) {



            if (preorder[i] < lower) {
                return false;
            }
            if (preorder[i] < st.top()) {
            }
            else {
                while (!st.empty() && st.top() < preorder[i]) {
                    lower = st.top();
                    st.pop();
                }
            }
            st.push(preorder[i]);
        }
        return true;
    }
};
