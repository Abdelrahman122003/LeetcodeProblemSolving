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
      int len = 0;
      ListNode* ptr = head;
      int mx = 0;
      deque<int>v;
      while(ptr != nullptr){
        v.push_back(ptr->val);
        ptr = ptr->next;
      }
      bool f = true;
      ptr = head;
      while(ptr != nullptr){
        if(f){
          ptr->val = v.front();
          v.pop_front();
          f = 0;
        }else{
          ptr->val = v.back();
          v.pop_back();
          f = 1;
        }
        ptr = ptr->next;
      }
    }
};