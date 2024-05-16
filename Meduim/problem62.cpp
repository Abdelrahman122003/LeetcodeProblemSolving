class Solution {
public:
        int _n, _m;
        static const int MOD = 2 * 1e9;
        int dp[100][100];
        bool check(int i, int j){
                return i >= 0 && j >= 0 &&  j < _m && i < _n;      
        }
    int uniquePaths(int m, int n) {
        _n = m, _m = n;
            memset(dp,  -1, sizeof dp);
            return solve(0, 0);
    }
        int solve(int i , int j){
                if(!check(i, j))
                        return 0;
                if(i == _n-1 && j == _m-1)
                        return 1;
                
                int &ret = dp[i][j];
                if(~ret)
                        return ret;
                ret = 0;
                (ret += solve(i+1, j))%=MOD;
                (ret += solve(i, j+1))%=MOD;
                
                ret %= MOD;
                return ret;
        }
};