class Solution {
public:
    // Direction vectors for moving right, down, left, and up
    vector<int> x = {0, 1, 0, -1}; // Corrected the last direction for moving up
    vector<int> y = {1, 0, -1, 0}; 

    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        // Initialize the matrix with -1
        vector<vector<int>> ans(m, vector<int>(n, -1));

        // Start position and initial direction (right)
        int i = 0, j = 0, dir = 0;

        // Fill the matrix in a spiral order using the linked list values
        while (head) {
            // Assign the current linked list node value to the matrix
            ans[i][j] = head->val;

            // Calculate the next position
            int newI = i + x[dir], newJ = j + y[dir];

            // Check if the next position is out of bounds or already filled
            if (newI < 0 || newJ < 0 || newI >= m || newJ >= n || ans[newI][newJ] != -1) {
                // Change direction in a clockwise manner
                dir = (dir + 1) % 4;
            }

            // Move to the next position
            i += x[dir];
            j += y[dir];

            // Move to the next node in the linked list
            head = head->next;
        }

        return ans;
    }
};
