class Solution {
public:
//    solution 1 
    // int n , m;
    //     int ans, total;
    // vector<vector<bool>>vis;
    // vector<vector<int>>g;
    // vector<int>x{0, 0, 1, -1}, y{1, -1, 0, 0};
    // bool check(int nx , int ny){
    //         return (nx >= 0 && ny >= 0 && nx < n && ny < m && g[nx][ny] && !vis[nx][ny]);
// }
//     void dfs(int i , int j)
//     {
//            vis[i][j]  = true;
//             for(int k = 0;k < 4;k++){
//                     int nx = x[k] + i, ny = y[k] + j;
//                     if(check(nx, ny))
//                             total+= g[nx][ny], dfs(nx, ny);
                            
//             }
//             // cout << total << "\n";
//             ans = max(ans, total);
//             vis[i][j] = false;
//             total-= g[i][j];

//     }
//     int getMaximumGold(vector<vector<int>>& grid) {
//         g = grid;
//             n = grid.size(), m = grid[0].size();
//         vis = vector<vector<bool>>(n, vector<bool>(m , false));
        
//             ans = 0, total = 0;
//             int mx = 0;
//             for(int i = 0 ;i < n; i++){
//                 for(int j = 0;j < m;j++){
//                         ans = 0, total = 0;
//                         if(!vis[i][j] && grid[i][j])
//                                 total += grid[i][j],
//                                 dfs(i, j),mx = max(mx, ans);
//                 }    
//             }
            
//             return mx;
//     }
//    solution 2
    int n , m;
    vector<vector<int>>g;
    vector<int>x{0, 0, 1, -1}, y{1, -1, 0, 0};
    bool check(int nx , int ny){
            return (nx >= 0 && ny >= 0 && nx < n && ny < m && g[nx][ny]);
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        g = grid;
        n = grid.size(), m = grid[0].size();
        int maxGold = 0;

        // Search for the path with the maximum gold starting from each cell
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
               if(g[i][j])
                        maxGold =
                    max(maxGold, dfsBacktrack(i, j));
            }
        }
        return maxGold;
    }


    int dfsBacktrack(int i, int j) {
        // Base case: this cell is not in the matrix or this cell has no gold
       if(!check(i, j))
               return 0;
        int maxGold = 0;

        // Mark the cell as visited and save the value
        int originalVal = g[i][j];
        g[i][j] = 0;

        // Backtrack in each of the four directions
        for (int k = 0; k < 4; k ++) {
                int nx = x[k] + i, ny = y[k] + j; 
            maxGold =
                max(maxGold,
                    dfsBacktrack(nx, ny));
        }
        // Set the cell back to its original value
        g[i][j] = originalVal;
        return maxGold + originalVal;
    }
};


