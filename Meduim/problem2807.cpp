class Solution {
public:
    // Function to calculate the Greatest Common Divisor (GCD) of two numbers
    int gcd(int a, int b) {
        // If the second number is zero, return the first number as the GCD
        if (b == 0)
            return a;
        
        // Recursively calculate the GCD of b and a % b
        return gcd(b, a % b); 
    }

    // Function to insert nodes with GCD values between each pair of existing nodes in the linked list
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        // Initialize the current pointer to the head of the linked list
        ListNode* curr = head;
        // Initialize the next pointer to the second node in the list
        ListNode* next = curr->next;
        
        // Traverse the linked list until the end is reached
        while (next) {
            // Create a new node with the GCD of the values of the current and next nodes
            ListNode* newNode = new ListNode(gcd(curr->val, next->val));
            // Insert the new node between the current and next nodes
            newNode->next = next;
            curr->next = newNode;
            // Move the current pointer to the next node in the original list
            curr = next;
            // Move the next pointer to the following node
            next = next->next;
        }
        
        // Return the modified linked list
        return head;
    }
};
