class Solution {
public:
        vector<int>x{0, 0 , -1, 1};
        vector<int>y{1, -1 , 0,0};
        bool check(int i, int j, int n, int m){
                return i >= 0 && i < n &&  j  >= 0 && j < m;
        }
    int islandPerimeter(vector<vector<int>>& grid) {
        int counter = 0;
            int n = grid.size(), m = grid[0].size();
            for(int i = 0;i < n; i++){
                    for(int j = 0 ;j < m;j++){
                            if(grid[i][j]){
                                    for(int k = 0; k < 4;k++){
                                        if(!check(i+x[k], j+y[k], n, m))
                                                counter++;
                                        if(check(i+x[k], j+y[k], n, m) && !grid[i+x[k]][j+y[k]])
                                                counter++;
                                }
                            }
                            
                    }
            }
            return counter;
    }
};