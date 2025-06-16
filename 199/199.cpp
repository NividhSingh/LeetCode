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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> topLevel;

        vector<int> v;
        if (!root) {
            return v;
        }

        topLevel.push(root);
        while (!topLevel.empty()) {
            v.push_back(topLevel.front()->val);
            queue<TreeNode*> nextLevel;

            while (!topLevel.empty()) {
                if(topLevel.front()->right) {
                    nextLevel.push(topLevel.front()->right);
                }
                if(topLevel.front()->left) {
                    nextLevel.push(topLevel.front()->left);
                }
                topLevel.pop();
            }
            topLevel = nextLevel;
        }
        return v;
        
    }
};
