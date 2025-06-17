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
    int kthSmallest(TreeNode* root, int k) {
        return (kthSmallest2(root, k))[1];
    }
    
    vector<int> kthSmallest2(TreeNode* root, int k) {
        if (!root) {
            return {0, 0};
        }
        if (k == 1 && !root->left) {
            return {-1, root->val};
        }
        vector<int> a = kthSmallest2(root->left, k);
        if (a[0] == -1) {
            return a;
        }
        else if (a[0] == k - 1) {
            return {-1, root->val};
        }
        vector<int> b = kthSmallest2(root->right, k - a[0] - 1);
        if (b[0] == -1) {
            return b;
        }
        return {b[0] + a[0] + 1, 0};
    }

};
