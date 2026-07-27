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
    void reorderList(ListNode* head) {
        // Create a slow and fast pointer to find the middle
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            cout<< prev->val << " ";
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if (slow == fast) {
            return;
        }
        prev->next = nullptr;
        // Reverse the second half
        ListNode* secondHead = nullptr;
        prev = nullptr;
        ListNode* next = nullptr;
        while (slow != nullptr) {
            next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        secondHead = prev;
        // join the two list
        ListNode* currentFirst = head;
        ListNode* currentTwo = secondHead;
        ListNode* actualNodeF;
        ListNode* actualNodeS;
        while (currentFirst != nullptr) {
            actualNodeF = currentFirst;
            actualNodeS = currentTwo;
            currentFirst = currentFirst->next;
            currentTwo = currentTwo->next;
            actualNodeF->next = actualNodeS;
            if(currentFirst != nullptr)
                actualNodeS->next = currentFirst;
        }
    }
};
