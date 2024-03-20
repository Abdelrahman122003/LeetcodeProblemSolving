class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* l_first = list1;
             ListNode* l_last = list1;
            int counter = 0;
            while(counter <= b){
                    if(counter < a-1)
                            l_first = l_first->next;
                    if(counter < b)
                            l_last = l_last->next;
                    counter++;
            }
            ListNode* l2 = list2;
            while(l2->next)
                    l2 = l2 -> next;
            l_first->next = list2; 
            l2->next = l_last->next;
            return list1;
            
    }
};