class Solution {
public:
    // Function to construct a 2D array from a 1D vector
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        
        // Check if the total number of elements (m * n) matches the size of the original vector
        if (n * m != original.size())
            // If not, return an empty 2D vector
            return {};
        
        // Initialize the 2D vector that will store the result
        vector<vector<int>> twoDArray;
        
        // Iterate over the original vector in chunks of size 'n'
        for (int i = 0; i < original.size(); i += n) {
            // Print the current starting index (for debugging purposes)
            cout << i << endl;
            
            // Create a temporary vector to store the current row of the 2D array
            vector<int> divide;
            
            // Fill the temporary vector with elements from the original vector
            // The inner loop runs from the current index 'i' to 'i + n'
            for (int j = i; j < n + i; j++)
                divide.push_back(original[j]);
            
            // Add the filled row to the 2D vector
            twoDArray.push_back(divide);
        }
        
        // Return the constructed 2D array
        return twoDArray;
    }
};
