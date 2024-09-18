class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int size = nums.size();
        
        // Vector to store the numbers as strings
        vector<string> strs;
        
        // Reserve space in the vector to avoid multiple memory reallocations
        strs.reserve(size);
        
        // Convert each integer in the input vector to a string and store it in strs
        for(auto k : nums)
            strs.push_back(to_string(k));
        
        // Sort the strings using a custom comparator that compares concatenated results
        // It compares a + b and b + a to ensure the larger concatenation comes first
        sort(strs.begin(), strs.end(), [](string &a, string &b){
            return a + b > b + a;
        });
        
        // Concatenate all the sorted strings into the result
        string result = "";
        for(auto k : strs)
            result += k;
        
        // If the first character of the result is '0', return "0" to avoid cases like "00"
        if(result[0] == '0')
            return "0";
        
        // Return the final concatenated largest number as a string
        return result;
    }
};
