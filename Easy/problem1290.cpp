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
    int getDecimalValue(ListNode* head) {
        string str = "";
        ListNode* ptr = head;
        while(ptr->next != nullptr){
            str += (ptr->val + '0');
            ptr = ptr->next;
        }
        str += (ptr->val + '0');
        int ans = 0, p = 0, index = 0;
        reverse(str.begin(), str.end());
        while(str.size() > index){
            if(str[index] == '1')ans += (pow(2,p));
            index++;p++;
        }
        return ans;
    }
};