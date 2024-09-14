class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // Find the maximum value in the array
        int mx = *max_element(nums.begin(), nums.end());
        
        // Initialize variables:
        // maxS will store the length of the longest subarray of the maximum value
        // counter will keep track of the current length of consecutive maximum values
        int maxS = 0, counter = 0;
        
        // Iterate through each element in the array
        for (auto k : nums) {
            if (k == mx) {
                // Increment counter if the current element is the maximum value
                counter++;
            } else {
                // Update maxS with the maximum length of consecutive maximum values found so far
                maxS = max(maxS, counter);
                // Reset counter for the next potential subarray
                counter = 0;
            }
        }
        
        // Final check to update maxS in case the longest subarray ends at the last element
        maxS = max(maxS, counter);
        
        // Return the length of the longest subarray consisting of the maximum value
        return maxS;
    }
};
