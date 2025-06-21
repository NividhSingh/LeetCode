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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* newHead = new ListNode(0, head);
        head = newHead;
        while (newHead && newHead->next && newHead->next->next) {
            ListNode* temp = newHead->next;
            newHead->next = newHead->next->next;
            temp->next = newHead->next->next;
            newHead->next->next = temp;
            newHead = newHead->next->next;
        }
        return head->next;
        
    }
};
