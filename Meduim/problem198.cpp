// first solution dp(up to bottom)
class Solution {
public:
        
        int dp[101];
        int solve(int i, vector<int>nums){
                if(nums.size() <= i)return 0;
                int &ret = dp[i];
                if(~ret)return ret;
                ret = max(solve(i+2,nums) + nums[i], solve(i+1, nums));
                return ret;
        }
    int rob(vector<int>& nums) {
             memset(dp, -1, sizeof dp);
           return solve(0, nums);
             
    }
};
// second solution dp(bottom to up) 
class Solution {
public:
    int rob(vector<int>& nums) {
            if(nums.size()==1)return(nums[0]);
            nums[1] = max(nums[0], nums[1]);
            for(int i = 2;i < nums.size();i++){
                    nums[i] = max(nums[i] + nums[i-2], nums[i-1]);
            }
            return nums[nums.size()-1];
    }
};