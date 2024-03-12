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
    ListNode* removeZeroSumSublists(ListNode* head) {
//             first put front node with val = 0 and next -> head
       ListNode* front = new ListNode(0, head);
        ListNode* start  = front;
//             range will delete it if sum = 0 
//             range is [start, end]

//             first loop begin of range
        while(start != nullptr){
                 ListNode* end = start->next;
                 int sum = 0;
//                 second loop end of range
                while(end != nullptr){
                        sum += end->val;
                        if(!sum)
                                start->next = end->next;
                        end = end->next;
                }
                start = start->next;
        }
     return front->next;
    }
};