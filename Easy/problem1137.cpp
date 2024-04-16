class Solution {
public:
     vector<int>dp;
//         iterative solution
    // int tribonacci(int n) {
    //      dp = vector<int>(40); 
    //      dp[0] = 0, dp[1] = 1, dp[2] = 1;
    //      for(int i = 3;i <= n;i++)
    //              dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    //         return dp[n];
    // }
//        Recursive solution
          int tribonacci(int n){
                  dp = vector<int>(40, -1); 
                  return fun(n, dp);
          }
          int fun(int n, vector<int>&dp){
                  if(n == 0)
                          return 0;
                  if(n == 1 || n == 2)
                          return 1;
                  int& ret = dp[n];
                  if(ret != -1)
                          return dp[n];
                  ret = fun(n-1, dp) + fun(n-2, dp) + fun(n-3, dp);
                  
                  return ret;
          }
   
};