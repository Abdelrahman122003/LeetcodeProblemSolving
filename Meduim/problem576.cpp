#define ll long long

class Solution {
public:
        static const ll MOD = 1e9+7, si = 51; 
        int _n, _m; 
        int dp[si][si][si];
       vector<int>x{0, 0 , 1 , -1},y{1, -1 , 0, 0}; 
    bool check(int i, int j)
    {
            return _n > i && _m > j && j >= 0 && i >= 0; 
    }
    int findPaths(int m, int n, int maxM, int sR, int sC) {
            _n = m, _m = n;
        // dp = vector<vector<ll>>(m, vector<ll>(n, -1));
            memset(dp, -1, sizeof dp);
            return solve(maxM, sR, sC);
    }
        int solve(int m, int r, int c){
//                 return 1 if this is a invalid move
                if(!check(r, c))
                        return 1;
//                 if moves become zero return 0
                if(!m)
                        return 0;
                int& ret = dp[r][c][m];
                if(~ret)
                        return ret;
                ret = 0;

                for(int i = 0 ;i < 4;i++)
                        (ret += solve(m-1, r+x[i], c+y[i]))%=MOD;
//             //  down
//                 (ret += solve(m-1, r + 1, c))%=MOD;
// //               up
//                 (ret += solve(m-1, r - 1, c))%=MOD;
// //                right 
//                 (ret += solve(m-1, r, c+1))%=MOD;
// //                 left
//                 (ret += solve(m-1, r, c-1))%=MOD;
                ret %= MOD;
                return ret;
        }
};