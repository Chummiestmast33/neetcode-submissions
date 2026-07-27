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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* resultHead = NULL;
        ListNode* prev = NULL;
        while (l1 != NULL || l2 != NULL) {
            // If theres is a value use that value intead use 0
            int l1Num = l1 != NULL ? l1->val : 0;
            int l2Num = l2 != NULL ? l2->val : 0;

            int result = l1Num + l2Num + carry;
            ListNode* resultNode = new ListNode(result % 10);
            if (prev != NULL) {
                prev->next = resultNode;
            }
            if (resultHead == NULL) {
                resultHead = resultNode;
            }
            prev = resultNode;
            carry = result / 10;
            if(l1 != NULL){
                l1 = l1->next;
            }
            if(l2 != NULL){
                l2 = l2->next;
            }
        }
        if(carry > 0){
            prev->next = new ListNode(carry);
        }
        return resultHead;
    }
};
