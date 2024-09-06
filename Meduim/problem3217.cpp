class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        // Initialize a set to store the values from the nums vector for quick lookup
        set<int> s;
        for (auto k : nums)
            s.insert(k);

        // Create a dummy node to help construct the modified list
        ListNode* ans = new ListNode(0);
        ListNode* current = ans; // Pointer to the last node in the new list

        // Iterate through the original linked list
        while (head != nullptr) {
            // If the current node's value is not in the set, add it to the new list
            if (!s.count(head->val))
                current->next = new ListNode(head->val), current = current->next; // Create a new node and move to it

            // Move to the next node in the original list
            head = head->next;
        }

        // Return the new list starting from the next of the dummy node
        return ans->next;
    }
};
