class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        // Create a set to store allowed characters
        set<int> s;
        
        // Insert each character of 'allowed' into the set
        // This ensures that only allowed characters are stored
        for(auto k : allowed)
            s.insert(k);
        
        // Initialize a counter to keep track of consistent strings
        int counter = 0;
        
        // Iterate through each word in the 'words' vector
        for(int i = 0; i < words.size(); i++) {
            // Get the current word
            string str = words[i];
            
            // Assume the word is consistent initially
            bool f = true;
            
            // Check each character in the current word
            for(auto k : str) {
                // If the character is not in the set of allowed characters, the word is inconsistent
                f = (s.count(k));
                if(!f)
                    break; // Exit the loop early if an inconsistent character is found
            }
            
            // Increment the counter if the word is consistent
            counter += (f);
        }
        
        // Return the total number of consistent strings
        return counter;
    }
};
