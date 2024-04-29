class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int res = nums[0];
            // Calculate the bitwise XOR of all elements of the original array 
            for(int i  = 1;i < nums.size();i++)
                    res ^= nums[i];
            int counter = 0;
             bool bit, bit2;
           while(res && k)
           {
                  bit = (res & 1);
                   bit2 = (k & 1);
                   res >>= 1;
                   k  >>= 1;
// compare res to k in their binary representation.

//for each different bit between the bitwise XOR of elements of the original array and k we have to flip exactly one bit of an element in nums to make that bit equal  
                   counter +=(bit != bit2);
           }
            while(res)
                    bit = (res&1), res >>= 1, counter+=(bit);
             while(k)
                    bit = (k&1), k >>= 1, counter+=(bit);
            return counter;
                   
    }
};



// 010 
// 001  --> 011
// 011  --> 000
// 100  --> 100

// 001