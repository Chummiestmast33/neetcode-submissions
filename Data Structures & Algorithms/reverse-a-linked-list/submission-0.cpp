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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode* lastElement = NULL;
        ListNode* current = head;
        ListNode* next = NULL;
        while (current->next != nullptr) {
            next = current->next;
            current->next = lastElement;
            lastElement = current;
            current = next;
        }
        current->next = lastElement;
        head = current;
        return head;
    }
};
