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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> topLevel;


        if (!root) {
            return -1;
        }

        
        int level = 1;
        int max_level = 1;
        int max_sum = root->val;

        topLevel.push(root);
        while (!topLevel.empty()) {
            queue<TreeNode*> nextLevel;
            int sum = 0;
            while (!topLevel.empty()) {
                if(topLevel.front()->right) {
                    nextLevel.push(topLevel.front()->right);
                }
                if(topLevel.front()->left) {
                    nextLevel.push(topLevel.front()->left);
                }
                sum += topLevel.front()->val;
                topLevel.pop();
            }
            if (sum > max_sum) {
                max_sum = sum;
                max_level = level;
            }
            level++;
            topLevel = nextLevel;
        }
        return max_level;
        
    }
};
