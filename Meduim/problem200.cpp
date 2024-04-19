class Solution {
public:
        vector<vector<bool>>vis;
        vector<vector<char>>g;
        vector<int>x{0, 0, -1, 1};
        vector<int>y{1, -1, 0, 0};
        int n , m;
        bool check(int i, int j){
                return i < n && j < m && i >= 0 && j >= 0 && g[i][j] == '1' && !vis[i][j];
        }
        void dfs(int i, int j){
                vis[i][j] = true;
                for(int k = 0; k < 4;k++){
                        if(check(i+x[k], j+y[k]))
                                dfs(i+x[k], j+y[k]);
                }
        }
    int numIslands(vector<vector<char>>& grid) {
        int counter = 0;
            g = grid;
            n = grid.size();
            m = grid[0].size();
            vis = vector<vector<bool>>(n, vector<bool>(m, false));
            
            for(int i = 0;i < n;i++){
                for(int j = 0;j < m;j++){
                        if(g[i][j] == '1' && !vis[i][j]){
                                counter++, 
                                dfs(i, j);
                        }
                }    
            }
            return counter;
            
    }
};