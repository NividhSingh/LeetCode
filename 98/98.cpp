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
    bool isValidBST(TreeNode* root) {
        return isValidOnlyMax(root->left, root->val) && isValidOnlyMin(root->right, root->val);
    }

    bool isValid(TreeNode* root, int min, int max) {
        if (!root) {
            return true;
        }
        else if (root->val <= min || root->val >= max) {
            return false;
        }
        return isValid(root->right, root->val, max) && isValid(root->left, min, root->val);
    }
    
    bool isValidOnlyMax(TreeNode* root, int max) {
        if (!root) {
            return true;
        }
        else if (root->val >= max) {
            return false;
        }
        return isValid(root->right, root->val, max) && isValidOnlyMax(root->left, root->val);
    }
    
    bool isValidOnlyMin(TreeNode* root, int min) {
        if (!root) {
            return true;
        }
        else if (root->val <= min) {
            return false;
        }
        return isValidOnlyMin(root->right, root->val) && isValid(root->left, min, root->val);
    }
};
