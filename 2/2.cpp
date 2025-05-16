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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* newHead = NULL;
        ListNode* current = NULL;
        while (l1 != NULL || l2 != NULL || carry != 0) {
            int sum = carry;
            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }
            ListNode* newNode = new ListNode(sum%10, NULL);
            if (newHead == NULL) {
                newHead = newNode;
                current = newNode;
            }
            else {
                current->next = newNode;
                current = current->next;
            }
            carry = (int) sum / 10;
        }
        if (newHead == NULL) {
            newHead = new ListNode(0, NULL);
        }
        return newHead;
    }
};
