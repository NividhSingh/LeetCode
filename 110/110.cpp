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
    bool isBalanced(TreeNode* root) {
        int l = lengths(root);
        return l != -1;
    }
    
    int lengths(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int leftLength = lengths(root->left);
        int rightLength = lengths(root->right);
        // cout << root->val << " " << leftLength << " " << rightLength << endl;;
        if (leftLength == -1 || rightLength == -1 || abs(leftLength - rightLength) > 1) {
            return -1;
        }
        return 1 + max(leftLength, rightLength);
    }
};
