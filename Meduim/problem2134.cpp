// **Solution Explanation:

// 1. If you think about this problem and test some test cases, you will realize that the total number of ones is crucial for solving it. This is because the goal is to make all the ones adjacent.

// 2. We want to create a subarray of nums consisting entirely of ones, with the length of this subarray equal to the total number of ones.

// 3. The operation allowed to solve this problem is swapping one index with another, and we want to minimize the number of operations

// 4. To handle the circular nature of the array, we will use a duplicate array technique by appending a copy of the original array to the end of itself.

// 5. To solve this problem, we have two options.

// -->First, calculate the prefix sum for zeros and take a subarray of size equal to the total number of ones, while minimizing the number of zeros in that subarray.

// For example, consider the original array:

// [0, 1, 1, 0, 1, 0, 1, 0]

// The prefix sum for zeros (one-based indexing) is:

// 0, 1, 1, 1, 2, 2, 3, 3, 4 (where indices are 0, 1, 2, 3, 4, 5, 6, 7, 8)

// Let’s assume total_ones = 3.

// We start from index 1 and calculate:

// mn = min(mn, prefix[i + total_ones] - prefix[i])

// This formula, prefix[i + total_ones] - prefix[i], computes the number of zeros in the range of the subarray we are considering, and we aim to minimize this number.

// Second, calculate the prefix sum for ones and take a subarray of size equal to the total number of ones, while maximizing the number of ones in that subarray.

class Solution {
public:
    int minSwaps(vector<int>& nums) {

            int mn = 1e6, total_one = 0, n = nums.size();
             // count total number of ones
             for(auto k : nums)
                     total_one += (k);
            // This is a very tricky idea          
            // To handle the circular part, copy the array and append it to the nums array.
            for(int i = 0; i < n;i++)
                    nums.push_back(nums[i]);
            // Calculate the prefix sum for zeros and minimize the sum over a range whose length is equal to the total number of ones
            vector<int>prefix_zeros((n*2)+1, 0);
            for(int i = 1; i <= n*2;i++)
                    prefix_zeros[i] = prefix_zeros[i-1] + (!nums[i-1]);
            for(int i = 1; i <= (n*2)-total_one;i++)
                    mn = min(mn, prefix_zeros[i+total_one] - prefix_zeros[i]);
            return mn;
    }
};

