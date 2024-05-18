class Solution {
public:
        // hint : all robots always will be in same row but different columns
        int dp[70][70][70];
        int n, m;
        vector<vector<int>> g;
        bool check(int i, int j)
        {
                return i >= 0 && j >= 0 && i < n && j < m;
        }
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
            memset(dp, -1, sizeof dp);
            g = grid;
            return solve(0, 0, m-1);
    }
        int solve(int i, int j, int jj){
                if(!check(i, j) || !check(i, jj))
                        return -1e9;
                if(i == n-1){
                        return g[i][j] + g[i][jj];
                }
                int& ret = dp[i][j][jj];
                if(~ret)
                        return ret;
                
                int res = 0;
                res += g[i][j];
                res += g[i][jj];
                int mx = 0;
                for(int k = -1; k < 2;k++)
                        for(int kk = -1; kk< 2;kk++)
                                
                        {
                                if(j+k < jj+kk)
                                        mx = max(mx, solve(i+1, j+k, jj+kk) + g[i][j] + g[i][jj]);
                        }
                
                res += mx;
                return ret = mx;
        }
};
