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
    int pairSum(ListNode* head) {
        ListNode* first = head;
        ListNode* second = head->next;
        stack<int> stk;
        stk.push(first->val);
        while (second && second->next) {
            first = first->next;
            stk.push(first->val);
            second = second->next->next;
        }
        second = first->next;
        int top_sum = stk.top() + second->val;
        while (!stk.empty()) {
            top_sum = max(stk.top() + second->val, top_sum);
            second = second->next;
            stk.pop();
        }
        return top_sum;
    }
};
