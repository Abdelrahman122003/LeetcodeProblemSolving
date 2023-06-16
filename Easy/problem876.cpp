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
    ListNode* middleNode(ListNode* head) {
        long long count = 0;
        ListNode* ptr = head;
        ListNode* res = head;
        while(ptr != nullptr){
            count++;
            ptr = ptr->next;
        }
        long long mid = (long long)(count/2);
        while(mid > 0){
            res = res->next;
            mid--;
        }
        return res;
    }
};