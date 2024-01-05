#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size(), mx = 1;
        vector<int>dp(size, 1);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < i; ++j) {
                if(nums[j] < nums[i] && dp[j]+1 > dp[i])
                    dp[i]++;
                mx = max(mx, dp[i]);
            }
        }
        return mx;
    }
};