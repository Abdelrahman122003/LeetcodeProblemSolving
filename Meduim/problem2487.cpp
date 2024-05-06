class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        vector<ListNode*>v;
            ListNode* ptr = head;
            while(ptr)
            {
                    while(!v.empty() && v.back()->val < ptr->val)
                            v.pop_back();
                    v.push_back(ptr), ptr = ptr->next;
            }
            for(int i = 1; i < v.size();i++)
                    v[i-1]->next = v[i];
            return v[0];
    }
};