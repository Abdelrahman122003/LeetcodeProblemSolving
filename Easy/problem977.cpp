class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(auto &k : nums)
                k *=k;
         sort(nums.begin(), nums.end());
         return nums;
    }
};