class Solution {
public:
    bool increasingTriplet(vector<int>& nums) 
    {
      if(nums.size() < 3)return false;
       long long i = LONG_LONG_MAX, j = LONG_LONG_MAX;
       for(int k = 0; k < nums.size();k++){
         if(nums[k] <= i){
           i = nums[k];
         }else if(nums[k] <= j){
           j = nums[k];
         }else{
           return true;
         }
       }
       return false;
    }
};