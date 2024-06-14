class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
            int counter = 0;
            for(int i = 1;i < nums.size();i++)
                    if(nums[i-1] >= nums[i])
                            counter += (nums[i-1] - nums[i])+1, nums[i] += (nums[i-1] - nums[i])+1;
            return counter;
    }
};