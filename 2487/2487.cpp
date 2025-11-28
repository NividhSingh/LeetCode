/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if (!head) {
            return head;
        }
        stack<ListNode*> stk;
        ListNode* current = head;
        while(current) {
            stk.push(current);
            current = current->next;
        }
        int maxSoFar = stk.top()->val;
        current = stk.top();
        stk.pop();
        while (!stk.empty()) {
            if (stk.top()->val >= maxSoFar) {
                stk.top()->next = current;
                current = stk.top();
                maxSoFar = current->val;
            }
            stk.pop();
        }
        return current;
    }
};
