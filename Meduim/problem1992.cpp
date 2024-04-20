class Solution {
public:
        vector<int>x{0,0,-1, 1};
        vector<int>y{1, -1,0,0};
        int n, m;
        vector<vector<int>>g;
        vector<vector<bool>>vis;
        bool check(int i, int j)
        {
                return i < n && j < m && i >= 0 && j >= 0 && g[i][j] && !vis[i][j];
        }
        void dfs(int i, int j, int &r, int &c){
                vis[i][j] = true;
                r = max(r, i), c = max(c, j);
                for(int k = 0;k < 4;k++){
                        if(check(i+x[k], j + y[k]))
                                dfs(i+x[k], j+y[k], r, c);
                }
        }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
            n = land.size();
            m = land[0].size();
            g = land;
            vis = vector<vector<bool>>(n, vector<bool>(m, false));
            vector<vector<int>>ans;
            int k = 0;
            for(int i = 0;i < n;i++){
                    for(int j = 0;j < m;j++){
                            vector<int>v;
                            int r = 0, c = 0;
                            if(g[i][j] && !vis[i][j])
                                  dfs(i, j, r, c), ans.push_back({i, j, r, c});
                }
            }
            
            return ans;
    }
};