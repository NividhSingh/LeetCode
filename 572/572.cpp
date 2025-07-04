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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) {
            return false;
        }
        if (checkSubTree(root, subRoot)) {
            return true;
        }
        return isSubtree(root->right, subRoot) || isSubtree(root->left, subRoot);
    }

    bool checkSubTree(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) {
            return true;
        }
        if (!root || !subRoot) {
            return false;
        }
        if (root->val != subRoot->val) {
            return false;
        }
        return (checkSubTree(root->right, subRoot->right) && checkSubTree(root->left, subRoot->left));
    }
};
