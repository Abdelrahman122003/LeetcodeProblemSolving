class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
           int n = grid.size(), m = grid[0].size(), counter = 0;
            for(int i = 0 ;i <= n-3;i++){
                    for(int j = 0;j <= m-3; j++){
                          if(isMagicSquares(i, j, grid))
                                  counter++;
                    }
            }
            return counter;
    }
        
        bool isMagicSquares(int i, int j, vector<vector<int>>& grid){
                   int sum = 0;
// Check if the grid contains all numbers from 1 to 9.
                    set<int>distinctNums, sums;
                    for(int k = i; k < i+3;k++){
                            for(int kk = j; kk < j + 3;kk++){
                                    if(grid[k][kk] > 9 || grid[k][kk] < 1)
                                            return false;
                                    distinctNums.insert(grid[k][kk]);
                            }
                    }
                  if(distinctNums.size() != 9)
                          return false;
// Calculate the sum of each row.
                    for(int k = 0; k < 3;k++)
                        sums.insert(grid[k+i][j] + grid[k+i][j+1] + grid[k+i][j+2]);
// Calculate the sum of each column.
                    for(int k = 0; k < 3;k++)
                           sums.insert(grid[i][j + k] + grid[i + 1][j + k] + grid[i + 2][j + k]);
// Calculate the sum of each diagonal.
                    sums.insert(grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2]);
                    sums.insert(grid[i+2][j] + grid[i+1][j+1] + grid[i][j+2]);
// Check if the set contains only one unique sum, indicating all sums are equal.
                if(sums.size() != 1)
                        return false;
                
                return true;
                
        }
};