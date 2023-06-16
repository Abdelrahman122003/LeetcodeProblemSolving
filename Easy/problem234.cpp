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
    bool isPalindrome(ListNode* head) {
        // vector<int>v;
        string str = "";
        while(head->next != nullptr){
            str.push_back(head->val);
            head = head->next;
        }
        str.push_back(head->val);
        string s = "";
        s = str;
        reverse(str.begin(), str.end());
        if(s == str){
            return true;
        }
        return false;
    }
};