class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int size = grid.size()-2;
            vector<vector<int>>ans(size, vector<int>(size, 0));
            for(int i = 0; i < size;i++){
                    for(int j = 0; j < size ;j++){
                            int mx = 0;
                            for(int ii = i ; ii < i+3;ii++)
                                    for(int jj = j ;jj < j+3;jj++)
                                            mx = max(mx, grid[ii][jj]);
                            ans[i][j] = mx;
                    }
            }
            return ans;
    }
};
