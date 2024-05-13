class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
//      To maximize any binary number(row in this problem), we flip the start of the row if it equals 0.
            int n = grid.size(), m = grid[0].size();
        for(int i = 0 ; i < n;i++)
              if(!grid[i][0])
                       for(int j = 0;j < m;j++)
                                grid[i][j] = (grid[i][j])?0:1;
//       To maximize a column, if the number of zeros is greater than the number of ones, we will flip this column.
        for(int i = 0; i < m;i++){
                int ones = 0;
                for(int j = 0 ;j < n;j++)
                        ones += (grid[j][i] == 1);
               if(n - ones > ones)
                       for(int j = 0 ;j < n;j++)
                                grid[j][i] = (!grid[j][i])?1:0;
        } 
        int getNumber = 0;
        for(int i = 0 ;i < n;i++)
        {
                int num = 0, numS = 1;
                for(int j = m-1 ; j >= 0 ;j--)
                         if(grid[i][j])num += (numS<<(m-(j+1)));
                 getNumber += num;
        }
        return getNumber;
    }
};

