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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* current = head;
        int numberNodes = 0;
        while (current != NULL) {
            current = current->next;
            ++numberNodes;
        }
        int subGroups = numberNodes / k;
        current = head;
        ListNode* prev;
        ListNode* next = NULL;
        ListNode* endLastList = NULL;
        ListNode* answer;
        for (int i = 1; i <= subGroups; i++) {
            ListNode* currentLastList = current;
            prev = NULL;
            for (int j = 1; j <= k; j++) {
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }
            if (endLastList != NULL) {
                endLastList->next = prev;
            } else {
                answer = prev;
            }
            endLastList = currentLastList;
        }
        if (current != NULL) {
            endLastList->next = current;
        }
        return answer;
    }
};
