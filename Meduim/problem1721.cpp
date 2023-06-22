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
        ListNode* ptr = head;
        ListNode* ptrC1 = head;
        while(ptr != nullptr){
          if(len < k){
            // break;
            ptrC1 = ptrC1->next;
          }
          ptr = ptr ->next;
          len++;
        }
        long idex2 = len - k+1;
        len = 1;
        ptr = head;
        while(ptr != nullptr)
        {
          if(len == idex2-1){
            swap(ptr->val, ptrC1->val);
            break;
          }
          ptr = ptr ->next;
          len++;
        }
        return head;
    }
};