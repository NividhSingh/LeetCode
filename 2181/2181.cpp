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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* newHead = head;
        while (head->next) {
            while (head->next->next->val != 0) {
                head->next->val += head->next->next->val;
                head->next->next = head->next->next->next;
            }
            head = head->next->next;
        }
        newHead = newHead->next;
        head = newHead;
        while (head) {
            head->next = head->next->next;
            head = head->next;
        }
        return newHead;

    }
};
