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