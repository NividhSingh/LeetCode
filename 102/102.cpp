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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> bigV;
        queue<TreeNode*> topLevel;

        if (!root) {
            return bigV;
        }
        

        
        topLevel.push(root);

        while (!topLevel.empty()) {
            vector<int> v;
            queue<TreeNode*> nextLevel;

            while (!topLevel.empty()) {
                v.push_back(topLevel.front()->val);

                if (topLevel.front()->left) {
                    nextLevel.push(topLevel.front()->left);
                }
                
                if (topLevel.front()->right) {
                    nextLevel.push(topLevel.front()->right);
                }

                topLevel.pop();
                
            }
            topLevel = nextLevel;
            bigV.push_back(v);
        }
        return bigV;
        

    }
};
