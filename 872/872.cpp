/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        stack<int> stk1, stk2;
        get_order(root1, stk1);
        get_order(root2, stk2);
        while (!stk1.empty() && !stk2.empty()) {
            if (stk1.top() != stk2.top()) {
                return false;
            }
            stk1.pop();
            stk2.pop();
        }
        return stk1.empty() && stk2.empty();
    }
    void get_order(TreeNode* root, stack<int>& stk) {
        if (!root) {
            return;
        }
        if (!root->right && !root->left) {
            stk.push(root->val);
            return;
        }
        get_order(root->left, stk);
        get_order(root->right, stk);
    }

};
