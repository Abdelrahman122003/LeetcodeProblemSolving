class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
      sort(nums.begin(), nums.end());
      int l = 0, r = nums.size()-1, count = 0;
      while(l < r){
          if(nums[l] + nums[r] == k){
              count++;
              l++;
              r--;
              continue;
          }
          if(nums[l]+nums[r] < k){
              l++;
              continue;
          }
          if(nums[l]+nums[r] > k){
              r--;
              continue;
          }
      }
      return count;
    }
};