class Solution {
public: 
        
//         counting problem
// state --> dp[The number of dice that have been used so far] , [current_sum]
        int _n, _tar, _k;
        const long long MOD = 1e9 + 7;
        vector<vector<long long>>dp;
        int solve(int i, int sum)
        {
//                 get answer --> return 1
                if(i == _n && sum == _tar)
                        return 1;
//             out of bound
              if(i ==  _n)
                      return 0;
                
                long long& ret = dp[i][sum];
                if(ret != -1)
                        return ret;
               ret= 0;
                for(int j = 1; j <= _k;j++){
                        if(j + sum <= _tar)
                                ret += solve(i+1, sum + j) % MOD;
                }
                ret %=  MOD;
                return ret;
        }
    int numRollsToTarget(int n, int k, int target) {
        _n = n, _tar = target, _k = k;
            dp = vector<vector<long long>>(n, vector<long long>(target+1, -1));
        return solve(0, 0); 
    }
};





