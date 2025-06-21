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
    TreeNode* bstToGst(TreeNode* root) {
        dobs(root, 0);
        return root;
    }

    int dobs(TreeNode* root, int additional) {
        if (!root) {
            return 0;
        }
        int right_val = dobs(root->right, additional);
        root->val += right_val;
        if (!root->right) {
            root->val += additional;
        }
        if (root->left) {
            int leftVal = dobs(root->left, root->val);
            return leftVal;
        }
        return root->val;
        
    }
};
