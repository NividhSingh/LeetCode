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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) {
            return head;
        }
        head = new ListNode(-1, head);

        ListNode* beforeHead = head;
        ListNode* nextSet = head->next;
        while (nextSet) {
            for (int i = 0; i < k; i++) {
                if (!nextSet) {
                    return head->next;
                }
                nextSet = nextSet->next;
            }

            ListNode* second = beforeHead->next->next;
            beforeHead->next->next = nextSet;
            ListNode* previous = beforeHead->next;
            ListNode* nextBeforeHead = previous;
            while (second->next != nextSet) {
                ListNode* temp = second->next;
                second->next = previous;
                previous = second;
                second = temp;
                
            }
            second->next = previous;
            beforeHead->next = second;
            beforeHead = nextBeforeHead;
        }

        return head->next;

    }
};
