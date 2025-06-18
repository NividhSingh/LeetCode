/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(true) {
            if (root == p || root == q) {
                return root;
            }
            if (root->val > p->val != root->val > q->val) {
                return root;
            }
            if (root->val > p->val) {
                // return lowestCommonAncestor(root->left, p, q);
                root = root->left;
            }
            else {
                root = root->right;
            }
        }
    }
};
