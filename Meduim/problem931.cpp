class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
            int n = matrix.size();
           for(int i = 1;i < n;i++){
                   for(int j = 0; j < n;j++){
                           int mn = matrix[i-1][j];
                           if(j)
                                   mn = min(matrix[i-1][j-1], mn);
                           if(j+1 < n)
                                   mn = min(matrix[i-1][j+1], mn);
                           matrix[i][j] += mn;
                   }
           }
           int ans = 1e5+5;
           for(int i = 0;i < n;i++)
                  ans = min(ans, matrix[n-1][i]);
            return ans;
    }
};