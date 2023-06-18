class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int mn = -1;
        int i = 0, j  = nums.size()-1;
        sort(nums.begin(), nums.end());
        while(i < j){
          mn = max(mn, nums[i] + nums[j]);
          i++;j--;
        } 
        return mn;
    }
};