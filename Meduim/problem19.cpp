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
        int len = 0;
        ListNode* ptr = head;
        while(ptr != nullptr){
          len++;
          ptr = ptr->next;
        }
        if(n == len){
          return head->next;
        }
        ptr  = head;
        while(ptr != nullptr){
          if(n+1 == len){
            break;
          }
          len--;
          ptr = ptr->next;
        } 
        if(n == 1){
          ptr->next = nullptr;
        }else{
          ptr->next = ptr->next->next;
        }
        return head;
    }
};