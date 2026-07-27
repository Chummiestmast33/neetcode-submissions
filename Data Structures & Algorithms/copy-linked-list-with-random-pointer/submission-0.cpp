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
        if(head == NULL){
            return NULL;
        }
        unordered_map<Node*, Node*> nodeValues;
        Node* copyHead = NULL;
        Node* current = head;
        Node* prev = NULL;
        while(current != NULL){
            Node* copy = new Node(current->val);
            if(copyHead == NULL){
                copyHead = copy;
            } 
            if(prev != NULL){
                prev->next = copy;
            }
            nodeValues.insert({current, copy});
            prev = copy;
            current = current -> next;
        }
        current = head;
        Node* currentCopy = copyHead;
        while(current != NULL){
            currentCopy->random = nodeValues[current->random];
            currentCopy = currentCopy->next;
            current = current->next;
        }
        return copyHead;
    }
};
