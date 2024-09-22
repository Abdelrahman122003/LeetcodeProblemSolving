// First Solution
// Time Complexity: O(NlogN)
// The first solution generates all numbers from 1 to n and then sorts them lexicographically.

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        // Initialize a vector of size n to store the result.
        vector<int> ans(n);
        
        // Fill the vector with numbers from 1 to n.
        for(int i = 1; i <= n; i++)
            ans[i-1] = i;
        
        // Sort the numbers lexicographically by comparing their string representations.
        sort(ans.begin(), ans.end(), [](int a, int b) {
            return to_string(a) < to_string(b); 
        });
        
        // Return the sorted list.
        return ans;
    }
};

// Second Solution
// This solution generates lexicographically ordered numbers directly without sorting.
// Time Complexity: O(N)

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        // Initialize the first number (lexicographically smallest) as 1.
        int currNum = 1;
        vector<int> ans;
        
        // Iterate n times to generate all the numbers in lexicographical order.
        for(int i = 0; i < n; i++) {
            // Add the current number to the result.
            ans.push_back(currNum);
            
            // If multiplying by 10 does not exceed n, move to the next "level".
            // This handles cases like moving from 1 to 10, or 2 to 20, etc.
            if(currNum * 10 <= n)
                currNum *= 10;
            else {
                // If multiplying by 10 exceeds n, check whether the current number ends in 9
                // or if it's greater than or equal to n. If so, remove trailing digits.
                while(currNum % 10 == 9 || currNum >= n)
                    currNum /= 10;
                
                // Increment the current number by 1.
                currNum += 1;
            }
        }
        // Return the lexicographically ordered numbers.
        return ans;
    }
};
