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
    ListNode* deleteMiddle(ListNode* head) {
        if (head->next == NULL) {
            return NULL;
        }
        ListNode* first = head;
        ListNode* second = head->next->next;
        while (second != NULL) {
            if (second->next == NULL) {
                break;
            }
            second = second->next->next;
            first = first->next;
        }
        first->next = first->next->next;
        return head;
    }
};
