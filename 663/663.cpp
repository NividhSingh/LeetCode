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
    map<TreeNode*, int> m;
public:
    bool checkEqualTree(TreeNode* root) {
        getSums(root);
        map<TreeNode*, int> m2 = m;

        return checkEqualTreesWithDistance(root, 0);
    }

    bool checkEqualTreesWithDistance(TreeNode* root, int difference) {
        if (!root || (!root->left && !root->right)) {
            return false;
        }
        if (root->right && (root->val + m[root->left] + difference == m[root->right])) {
            return true;
        }
        if (root->left && (root->val + m[root->right] + difference == m[root->left])) {
            return true;
        }
        return checkEqualTreesWithDistance(root->left, difference + root->val + m[root->right]) || checkEqualTreesWithDistance(root->right, difference + root->val + m[root->left]);

    }

   int getSums(TreeNode* root) {
        if (!root) {
            return 0;
        }
        m[root] = getSums(root->right) + getSums(root->left) + root->val;
        return m[root];
    }
};
