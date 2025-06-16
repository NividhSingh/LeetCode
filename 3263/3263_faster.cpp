/**
 * Definition for doubly-linked list.
 * class Node {
 *     int val;
 *     Node* prev;
 *     Node* next;
 *     Node() : val(0), next(nullptr), prev(nullptr) {}
 *     Node(int x) : val(x), next(nullptr), prev(nullptr) {}
 *     Node(int x, Node *prev, Node *next) : val(x), next(next), prev(prev) {}
 * };
 */
class Solution {
public:
	vector<int> toArray(Node *head){
        int size = 0;
        Node* current = head;
        while (current) {
            size++;
            current = current->next;
        }
        vector<int> v(size);
        int i = 0;
        while(head) {
            v[i] = head->val;
            i++;
            // v.push_back(head->val);
            head = head->next;
        }
        return v;
    }
};
