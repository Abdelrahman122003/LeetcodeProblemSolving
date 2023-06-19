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
    ListNode* oddEvenList(ListNode* head) {

      if(head == nullptr){return nullptr;}
      int count = 1;
      ListNode* ptr;
      ptr = head;
      queue<ListNode*>qO;
      queue<ListNode*>qE;
      while(ptr != nullptr){
        if(count%2){
          qO.push(ptr);
        }else{
          qE.push(ptr);
        }
        count++;
        ptr = ptr->next;
      }
      ListNode* h = head;
      ListNode* hS;
      hS = h;
      qO.pop();
      while(!qO.empty()){
        ListNode* store;
        store = qO.front();
        qO.pop();
        store->next = nullptr;
        h ->next = store;
        h = h->next;
      }
       while(!qE.empty()){
         ListNode* store;
        store = qE.front();
        qE.pop();
       store->next = nullptr;
       h->next = store;
        h = h->next;
      }
      return hS;
    }
};