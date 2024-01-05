#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        int size = nums.size(), mx = 1;
        vector<int> dp(size, 1);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < i; ++j) {
//                check if elements in indices(0 -> i) less than element in index i using this condition nums[j] < nums[i]
//               and check this element(0 -> i) valid if we put it in sequence or no using this condition dp[i] < dp[j]+1
                if (nums[j] < nums[i] && dp[j] + 1 > dp[i])
                    dp[i]++;
                mx = max(mx, dp[i]);
            }
        }
        return mx;
    }
};