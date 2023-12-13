class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        ios_base::sync_with_stdio(false); 
        cin.tie(nullptr);                 
        cout.tie(nullptr);
        map<int, int>mRow, mColumn;
        for (int i = 0; i < mat.size(); ++i) {
            for (int j = 0; j < mat[i].size(); ++j) {
                if(mat[i][j])mRow[i]++, mColumn[j]++;
            }
        }
        int count = 0;
        for (int i = 0; i < mat.size(); ++i) {
            for (int j = 0; j < mat[i].size(); ++j) {
                if(mRow[i] == 1 && mColumn[j] == 1 && mat[i][j] == 1)count++;
            }
        }
    return count;
    }
};