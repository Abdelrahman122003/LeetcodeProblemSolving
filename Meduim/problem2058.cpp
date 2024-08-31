class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        // Vector to store positions of critical points and the result
        vector<int> positions, ans{-1, -1};
        
        // Initialize pointers to traverse the list
        ListNode* prev = head;          // Previous node
        ListNode* curr = head->next;    // Current node
        int pos = 1;                    // Position counter starting from 1
        
        // Traverse the linked list to find critical points
        while (curr->next) { 
            // Check for local minima: prev > curr < next
            if (prev->val > curr->val && curr->next->val > curr->val)
                positions.push_back(pos);
            // Check for local maxima: prev < curr > next
            if (prev->val < curr->val && curr->next->val < curr->val)
                positions.push_back(pos);
            
            // Move to the next set of nodes
            pos++;                       // Increment position counter
            prev = prev->next;           // Move prev to the next node
            curr = curr->next;           // Move curr to the next node
        }

        // If there are at least two critical points, calculate distances
        if (positions.size() >= 2) {
            // Sort the critical points' positions
            sort(positions.begin(), positions.end());

            // Maximum distance is the distance between the first and last critical points
            ans[1] = positions.back() - positions[0];

            // Initialize minimum distance with a large number
            ans[0] = 1e9;
            for (int i = 1; i < positions.size(); i++)
                // Calculate minimum distance between consecutive critical points
                ans[0] = min(ans[0], positions[i] - positions[i - 1]);
        }

        // Return the minimum and maximum distances
        return ans;
    }
};
