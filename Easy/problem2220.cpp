class Solution {
public:

    // Function to calculate the minimum number of bit flips required to convert 'start' to 'goal'
    int minBitFlips(int start, int goal) {
        int ans = 0;  // Variable to count the number of bit flips
        
        // Loop while both 'start' and 'goal' are non-zero
        while (start && goal) {
            // Increment 'ans' if the least significant bit of 'start' and 'goal' are different
            ans += ((start & 1) != (goal & 1));
            
            // Right shift 'start' and 'goal' by 1 bit to process the next bit
            start >>= 1;
            goal >>= 1;
        }
        
        // Process any remaining bits in 'start' if 'goal' is zero
        while (start) {
            // Increment 'ans' for each remaining bit in 'start'
            ans += (start & 1);
            
            // Right shift 'start' by 1 bit
            start >>= 1;
        }
        
        // Process any remaining bits in 'goal' if 'start' is zero
        while (goal) {
            // Increment 'ans' for each remaining bit in 'goal'
            ans += (goal & 1);
            
            // Right shift 'goal' by 1 bit
            goal >>= 1;
        }
        
        // Return the total number of bit flips required
        return ans;
    }
};
