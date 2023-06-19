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
    int pairSum(ListNode* head) {
      vector<int>v;
      ListNode* ptr = head;
      while(ptr != nullptr){
        v.push_back(ptr->val);
        ptr = ptr->next;
      }
      int mx = 0;
      int i = 0, j = v.size()-1;
      while(i < j){
        mx = max(mx, v[i] + v[j]); 
        i++;
        j--;
      }
      return mx;
    }
};