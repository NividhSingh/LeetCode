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
    int diameterOfBinaryTree(TreeNode* root) {
        return lengths(root)[1];
    }

    vector<int> lengths(TreeNode* root) {
        if (!root) {
            return {-1, -1};
        }
        vector<int> l = lengths(root->left);
        vector<int> r = lengths(root->right);
        int combinedPath = l[0] + r[0] + 2;
        int maxLength = max(l[0], r[0]) + 1;
        return {maxLength, max(max(combinedPath, l[1]), r[1])};
    }
};
