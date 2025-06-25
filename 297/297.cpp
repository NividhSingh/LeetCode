/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) {
            return "[]";
        }
        string s = "[";
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            if (q.front() == NULL) {
                s += "null,";
            }
            else {
                s += to_string(q.front()->val);
                s += ",";
                q.push(q.front()->left);
                q.push(q.front()->right);
            }
            q.pop();
        }
        s[s.length() - 1] = ']';
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.length() == 2) {
            return NULL;
        }
        vector<string> tokens = tokenize(data, ',');
        queue<bool> b;
        queue<TreeNode*> t;
        TreeNode* head = new TreeNode(stoi(tokens[0]));
        t.push(head);
        t.push(head);
        b.push(true);
        b.push(false);
        for (int i = 1; i < tokens.size(); i++) {
            TreeNode* nextNode;
            if (tokens[i] == "null") {
                nextNode = NULL;
            }
            else {
                nextNode = new TreeNode(stoi(tokens[i]));
            }
            if (b.front()) {
                t.front()->left = nextNode;
            }
            else {
                t.front()->right = nextNode;
            }
            if (nextNode) {
                t.push(nextNode);
                t.push(nextNode);
                b.push(true);
                b.push(false);
            }
            t.pop();
            b.pop();
        }
        return head;
    }

    vector<string> tokenize(string str, char delim) {
        int i = 1;
        int e = 1;
        vector<string> v;
        while (i < str.length() - 1) {
            e = i;
            while (e < str.length() - 1 && str[e] != delim) {
                e++;
            }
            v.push_back(str.substr(i, e - i));
            i = e + 1;
        }
        // v.push_back(str.substr(i, e - i));
        return v;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
