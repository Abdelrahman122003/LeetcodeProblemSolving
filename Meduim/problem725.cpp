class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        // Initialize a vector of size 'k' with nullptr to store the result parts
        vector<ListNode*> parts(k, nullptr);
        int size = 0;   
        
        // Calculate the size of the linked list
        ListNode* curr = head;
        while (curr) {
            size++;
            curr = curr->next;
        }
        
        // Determine the base size of each part and the extra nodes (remainder)
        int sizeP = size / k; // Minimum size of each part
        int reminder = size % k; // Remaining nodes to distribute across the parts
        
        // Reset the current pointer to the head of the linked list
        curr = head;

        // Iterate through 'k' parts and split the linked list
        for (int i = 0; i < k && curr; i++) {
            // Assign the start of the current part to the result vector
            parts[i] = curr;
            
            // Calculate the size of the current part, including extra nodes if needed
            int sizeCurrPart = sizeP + (reminder > 0 ? 1 : 0);
            reminder--;  // Decrement the remainder as an extra node is added
            
            // Traverse to the end of the current part
            for (int j = 1; j < sizeCurrPart; j++)
                curr = curr->next;
            
            // Break the current part from the rest of the linked list
            ListNode* newHead = curr->next;  // Store the head of the next part
            curr->next = nullptr;  // Set the end of the current part to null
            curr = newHead;  // Move to the next part
        }
        
        return parts;  // Return the split parts
    }
};
