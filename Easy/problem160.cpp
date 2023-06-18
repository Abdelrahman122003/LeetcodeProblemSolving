/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptr1;
        ListNode *ptr2;
        ptr1 = headA;
        ptr2 = headB;
        set<ListNode*>s;
        while(ptr1 != nullptr){
          s.insert(ptr1);
          ptr1 = ptr1->next;
        }
        while(ptr2 != nullptr){
          if(s.count(ptr2)){
            return ptr2;
          }
          ptr2 = ptr2->next;
        }
        return nullptr;
    }
};