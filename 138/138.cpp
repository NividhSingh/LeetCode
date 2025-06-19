/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return NULL;
        }
        map<Node*, Node*> m;
        Node* newHead = new Node(head->val);
        Node* current1 = head;
        Node* current2 = newHead;
        m[current1] = current2;
        while (current1->next) {
            Node* temp = new Node(current1->next->val);
            current2->next = temp;
            m[current1->next] = temp;
            current1 = current1->next;
            current2 = current2->next;
        }
        current1 = head;
        current2 = newHead;
        while (current2) {
            current2->random = m[current1->random];
            current2 = current2->next;
            current1 = current1->next;
        }

        return newHead;

    }
};
