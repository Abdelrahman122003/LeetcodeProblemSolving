class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false); 
        cin.tie(nullptr);                 
        cout.tie(nullptr);
        map<int, int>mRow, mColumn, mRowZero, mColumnZero;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if(grid[i][j])mRow[i]++, mColumn[j]++;
                 if(!grid[i][j])mRowZero[i]++, mColumnZero[j]++;
            }
        }
        vector<vector<int>>ans;
        ans.resize(grid.size(), vector<int>(grid[0].size()));
        int count = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
              ans[i][j] = mRow[i] + mColumn[j] - mRowZero[i] - mColumnZero[j];
            }
        }
    return ans;
    }
};