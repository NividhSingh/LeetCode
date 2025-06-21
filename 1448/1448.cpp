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
    int goodNodes(TreeNode* root) {
        return findGoodNodes(root, root->val);
    }
    int findGoodNodes(TreeNode* root, int maxSoFar) {
        if (!root) {
            return 0;
        }
        int s = 0;
        if (root->val >= maxSoFar) {
            // cout << root->val;
            s++;
            maxSoFar = root->val;
        }
        // cout << " " << root->val << " " << maxSoFar << endl;
        maxSoFar = max(maxSoFar, root->val);
        s += findGoodNodes(root->left, maxSoFar) + findGoodNodes(root->right, maxSoFar);
        return s;
    }
};
