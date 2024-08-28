// This is a greedy problem because we start by removing the substrings "ab" or "ba" based on which one has the higher point value.

class Solution {
public:
    int answer; // Variable to store the total points 

    // Main function to calculate the maximum points by removing "ab" or "ba" substrings
    int maximumGain(string s, int x, int y) {
        answer = 0; // Initialize answer to 0

        // Decide the order of removal based on which substring has a higher point value
        // Remove the higher value substring first to maximize the gain
        if (x > y)
            remove_ab_or_ba(s, "ab", x), remove_ab_or_ba(s, "ba", y); // Remove "ab" first if x > y
        else
            remove_ab_or_ba(s, "ba", y), remove_ab_or_ba(s, "ab", x); // Remove "ba" first if y > x

        return answer; // Return the total points
    }

    // Helper function to remove a specific substring ("ab" or "ba") and add points
    void remove_ab_or_ba(string &s, string sub, int val) {
        string after = ""; // String to build the modified version of s after removals
        // Iterate through the string to check and remove the target substring
        for (int i = 0; i < s.size(); i++) {
            // Check if the last character of 'after' and current character of 's' form the target substring
            if (!after.empty() && after.back() == sub[0] && s[i] == sub[1]) {
                answer += val;  // Increment the points by the given value
                after.pop_back(); // Remove the last character of 'after' to "delete" the substring
            } else {
                after += s[i]; // Otherwise, add the current character to 'after'
            }
        }
        s = after; // Update the original string with the modified version
    }
};
