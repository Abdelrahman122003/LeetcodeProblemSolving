class Solution {
public:
        vector<int>dp;
    int climbStairs(int n) {
            dp = vector<int>(n+1, -1);
            return solve(n);
    }
        int solve(int n){
                if(n < 0)
                        return 0;
                if(n == 0)
                        return 1;
                int &ret = dp[n];
                if(~ret)
                        return ret;
                ret = (solve(n-1) + solve(n-2));
                return ret;
        }
};