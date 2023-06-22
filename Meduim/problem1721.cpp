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
    ListNode* swapNodes(ListNode* head, int k) {
        long len = 1;
        ListNode* ptr1 = head;
        ListNode* ptrC1 = head;
        ListNode* ptr2 = head;
        ListNode* ptrC2 = head;

        while(ptr1 != nullptr){
          if(len < k){
            ptrC1 = ptrC1->next;
          }
          ptr1 = ptr1 ->next;
          len++;
        }
        long index2 = len - k;
        len = 1;
        while(ptr2 != nullptr){
          if(len < index2){
            ptrC2 = ptrC2->next;
          }
          ptr2 = ptr2 ->next;
          len++;
        }
        swap(ptrC1->val, ptrC2->val);
        return head;
    }
};