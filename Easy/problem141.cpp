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
    bool hasCycle(ListNode *head) {
        set<ListNode*>s;
        int count = 0;
        ListNode * ptr = head;
        while(ptr != nullptr)
        {
          if(count == 0){
            s.insert(ptr);
            ptr = ptr->next; 
            count++;
            continue;
          }
          if(s.count(ptr)){
            return true;
          }
          s.insert(ptr);
          ptr = ptr->next;
        }
        return false;
    }
};