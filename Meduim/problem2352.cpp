class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
      // loop for rows
       int ans = 0;
        for (int i = 0;i < grid.size();i++){
          // loop for col
          for(int j = 0;j < grid.size();j++){
            ans++;
            for(int kk = 0;kk < grid.size();kk++){
              if(grid[i][kk] != grid[kk][j]){
                ans--;
                break;
              }
            }
          }
        }
        return ans;
    }
};