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
    // ListNode *prev;
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *cur = head;
        ListNode* next = nullptr;
        ListNode* pre = nullptr;
        // stack<ListNode>s;
        
        if(cur == nullptr || cur->next == nullptr){
          return head;
        }
        while(cur != nullptr){
          // store next
          next = cur->next;
          // change cut -> next
          cur->next = pre;
          pre = cur;
          cur = next;
        }
        return pre;
    }
};