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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return NULL;
        }
        ListNode* head = new ListNode(0, NULL);
        ListNode* last = head;
        vector<int> indecies(lists.size());
        int minIndex = -1;
        int minValue;
        int moreLeft = true;
        while (moreLeft) {
            minIndex = -1;
            moreLeft = false;
            for (int i = 0; i < lists.size(); i++) {
                if (lists[i] != NULL) {
                    moreLeft = true;
                    if (minIndex == -1 || lists[i]->val < minValue) {
                        minIndex = i;
                        minValue = lists[i]->val;
                    }
                }
            }
            if (!moreLeft) {
                break;
            }
            else {
                last->next = lists[minIndex];
                last = last->next;
                lists[minIndex] = lists[minIndex]->next;
            }
        }
        last->next = NULL;
        return head->next;
    }
};
