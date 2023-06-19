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
    ListNode* deleteDuplicates(ListNode* head) {
      if(head==nullptr){
        return head;
      }
      ListNode* ptr = head;
      ListNode* newH;
      ListNode* h = head;
      newH = h;
      set<int>s;
      s.insert(h->val);
      while(ptr != nullptr){
        if(!s.count(ptr->val)){
          s.insert(ptr->val);
          h->next = ptr; 
          h = h->next;
        }
        ptr = ptr->next;
      }
      h->next = nullptr;
      return newH;
    }
};