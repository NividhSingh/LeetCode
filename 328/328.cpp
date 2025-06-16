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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = head;
        if (!odd) {
            return head;
        }
        ListNode* evenStart = odd->next;
        ListNode* evenEnd = odd->next;

        if (!evenStart) {
            return head;
        }
        ListNode* temp = evenStart->next;

        while(temp) {
            odd->next = temp;
            odd = odd->next;
            temp = temp->next;
            if (!temp) {
                break;
            }
            evenEnd->next = temp;
            evenEnd = evenEnd->next;
            temp = temp->next;
        }
        odd->next = evenStart;
        evenEnd->next = NULL;
        return head;
        
        
        // ListNode* start = new ListNode(0, head);
        // ListNode* odd = start;
        // ListNode* even = start;
        // while(odd && odd->next && odd->next->val%2 ==  1) {
        //     odd = odd->next;
        // }
        // ListNode* beforeOdd = odd;
        // while (beforeOdd && beforeOdd->next) {
        //     while (beforeOdd && beforeOdd->next && beforeOdd->next->val % 2 == 0) {
        //         beforeOdd = beforeOdd->next;
        //     }
        //     ListNode* temp = beforeOdd->next;
        //     beforeOdd->next = beforeOdd->next->next;
        //     temp->next = odd->next;
        //     odd->next = temp;
        //     odd = odd->next;
        // }
        // return start->next;
    }
};
