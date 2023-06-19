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
    ListNode* deleteMiddle(ListNode* head) {
      int count = 0;
       ListNode* ptr;
       ptr = head;  
       while(ptr != nullptr){
         count++;
         ptr = ptr->next;
       }
       if(count == 1)return nullptr;
       int mid = count/2;
       ptr = head;
       int c = 0;
       while(c <= mid-1){
         if(mid-1 == c){
           ptr->next = ptr->next->next;
         }
         c++;
         ptr = ptr->next;
       }
       return head;
    }
};