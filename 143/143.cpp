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
    void reorderList(ListNode* head) {
        stack<ListNode*> stk;
        ListNode* current = head;
        int c = 0;
        while (current) {
            stk.push(current);
            current = current->next;
            ++c;
        }

        current = head;

        for (int i = 0; i < c/2; i++) {
            cout << stk.top()->val << endl;
            stk.top()->next = current->next;
            current->next = stk.top();
            stk.pop();
            current = current->next->next;
        }

        current->next = NULL;
    }
};
