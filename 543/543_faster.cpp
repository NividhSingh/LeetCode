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
private: 
    int d;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        d = 0;
        lengths(root);
        return d;
    }

    int lengths(TreeNode* root) {
        if (!root) {
            return -1;
        }
        int l = lengths(root->left);
        int r = lengths(root->right);
        int combinedPath = l + r + 2;
        int maxLength = max(l, r) + 1;
        d = max(d, combinedPath);
        return maxLength;
    }
};
