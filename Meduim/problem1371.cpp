class Solution {
public:
    int findTheLongestSubstring(string s) {
        
        // Initialize variables
        int ans = 0, size = s.size(), mask = 0;
        
        // Map to store the first occurrence of each mask (vowel state pattern)
        unordered_map<int, int> states;
        
        // The initial mask (all vowels appearing an even number of times) starts at index -1
        states[mask] = -1;

        // Iterate over each character in the string
        for (int i = 0; i < size; i++) {

            // Toggle the bits of the mask based on the current vowel encountered
            // Each vowel corresponds to a specific bit position in the mask
            if (s[i] == 'o')
                mask ^= (1 << 0);  // Toggle the bit for 'o' (1st bit)
            else if (s[i] == 'i')
                mask ^= (1 << 1);  // Toggle the bit for 'i' (2nd bit)
            else if (s[i] == 'u')
                mask ^= (1 << 2);  // Toggle the bit for 'u' (3rd bit)
            else if (s[i] == 'e')
                mask ^= (1 << 3);  // Toggle the bit for 'e' (4th bit)
            else if (s[i] == 'a')
                mask ^= (1 << 4);  // Toggle the bit for 'a' (5th bit)
            
            // If the current mask (vowel state) has been seen before,
            // this means the substring between the previous index and the current one
            // has an even number of vowels for all vowels.
            if (states.find(mask) != states.end())
                ans = max(ans, i - states[mask]);  // Update the maximum length of the substring
            else
                states[mask] = i;  // Record the first occurrence of the current mask
        }
        
        return ans;  // Return the length of the longest valid substring
    }
};
    
// Test case with traceing 

//    a e i o u  ind
//    0 0 0 0 0  -1       No Thing 
// e  0 1 0 0 0   0 
// l  0 1 0 0 0   1
// e  0 0 0 0 0   2
// e  0 1 0 0 0   3
// t  0 1 0 0 0   4 
// m  0 1 0 0 0   5
// i  0 1 1 0 0   6 
// n  0 1 1 0 0   7
// i  0 1 0 0 0   8
// c  0 1 0 0 0   9
// o  0 1 0 1 0   10
// w  0 1 0 1 0   11
// o  0 1 0 0 0   12
// r  0 1 0 0 0   13
// o  0 1 0 1 0   14
// e  0 0 0 1 0   15
// p  0 0 0 1 0   16