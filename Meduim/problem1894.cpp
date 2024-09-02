class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        // Calculate the total sum of chalk required to complete one full cycle
        long long sum = 0;
        for (auto c : chalk) 
            sum += c;        
        
        // Compute the remainder of chalk needed after completing full cycles
        int remainder = k % sum;

        // Iterate through the chalk vector to find the index where the remainder is less than the chalk needed
        for (int i = 0; i < chalk.size(); i++) {  
            if (remainder < chalk[i])  
                return i; 
            else
                remainder -= chalk[i];  // Subtract the chalk needed at the current index from the remainder
        }
        
        // This line will never be reached as the loop will always return an index
        return -1;
    }
};
