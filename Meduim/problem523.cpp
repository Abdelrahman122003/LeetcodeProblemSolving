// The idea of this problem is:
// 1. Calculate the prefix sum for the input array.
// 2. Compute the mod of each prefix sum with respect to k for the entire array.
// 3. When the mod value at a current index (e.g., index 4) equals the mod value at a previous index (e.g., index 1),
//    it means that the subarray sum between these indices (index 1 to index 4) is a multiple of k.

// for example 
// [23,2,4,6,7]
// 6
// indies --> [0, 1, 2, 3, 4]
// prefix --> [23, 25, 29, 35, 42]
// modes  --> [5, 1, 5, 5, 0]

// prefix[3] - prefix[0] = 12 is mulipule of k

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
            map<int, int>m;
            int prefix = 0;
// This initializes the condition where if the mod prefix is equal to zero, 
// it means that the sum of the array from the first element to the current element 
// is a multiple of k. Therefore, no zero is recorded in the map initially.
            m[0] = -1;
            for(int i = 0;i < nums.size();i++){
                    prefix += nums[i];
                    int mod = prefix%k;
                    if(m.find(mod) != m.end())
                            if(i - m[mod] > 1)
                                    return true;
                    else 
                            m[mod] = i;
            }
            return false;
    }
};

// [1,2,12]
// 6
// prefix --> [1, 3, 15]

// [5,0,0,0]
// 3
// prefix --> [5, 5, 5, 5]


// [23,2,4,6,7]
// 6
// 18 24 30 36 42 48
// prefix --> [23, 25, 29, 35, 42]
// modes  --> [5, 1, 5, 5, 0]

// [23,2,4,6,6]
// 7

//prefix --> [23, 25, 29, 35, 41]
//modes  --> [2, 4, 1, 0, 6]
