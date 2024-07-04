class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* newHead = new ListNode(0);
        ListNode* move = newHead;
        int sum = 0;
            ListNode* curr = head->next;
            while(curr){
                  if(!curr->val)
                          move->next = new ListNode(sum), move = move->next, sum = 0;
                   else
                           sum += curr->val;
                    curr = curr->next;    
            }
            return newHead->next;
    }
};
