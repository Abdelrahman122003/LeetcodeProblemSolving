class Solution {
public:
    // Function to answer XOR queries on an array
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        // Get the size of the input array
        int size = arr.size();
        
        // Create a prefix XOR array with one extra element (initialized to 0)
        vector<int> XorPre(size + 1, 0);
        
        // Fill the prefix XOR array
        // XorPre[i] will hold the XOR of all elements from arr[0] to arr[i-1]
        for(int i = 1; i <= size; i++)
            XorPre[i] = arr[i - 1] ^ XorPre[i - 1];
        
        // Clear the input array as it's no longer needed
        arr.clear();
        
        // Process each query
        for(int i = 0; i < queries.size(); i++) {
            // Extract the start and end indices of the subarray for the current query
            int start = queries[i][0];
            int end = queries[i][1];
            
            // Calculate the XOR of the subarray using the prefix XOR array
            // The result for the subarray arr[start] to arr[end] is given by:
            // XorPre[end + 1] ^ XorPre[start]
            arr.push_back(XorPre[end + 1] ^ XorPre[start]);
        }
        
        // Return the results of the queries
        return arr;
    }
};
