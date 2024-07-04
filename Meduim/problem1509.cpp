class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());            
        if(nums.size() <= 4)
                return 0;
            int n = nums.size(), minDiff = INT_MAX; 
        for(int i = 0, j = n-4; i < 4;i++, j++)
            minDiff = min(minDiff, nums[j] - nums[i]);
            
      return minDiff;
    }
};