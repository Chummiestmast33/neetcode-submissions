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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* pointer1 = head;
        ListNode* pointer2 = head;
        for (int i = 0; i < n; i++) {
            pointer2 = pointer2->next;
        }
        ListNode* prev = NULL;
        while(pointer2 != NULL){
            prev = pointer1;
            pointer1 = pointer1->next;
            pointer2 = pointer2->next;
        }
        if(prev == NULL){
            return pointer1->next;
        }
        prev->next = pointer1->next;
        return head;
    }
};
