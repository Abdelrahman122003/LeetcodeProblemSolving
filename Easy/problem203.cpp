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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr){
            return nullptr;
        }
        ListNode* n = new ListNode(0);
        n->next = head; 
        ListNode* ptr = n;
        while(ptr->next != nullptr){
            if(ptr->next->val == val){
                ptr->next = ptr->next->next; 
            }
            ptr = ptr->next;  
        }
        return n->next;
    }
};