class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int>ans;
            set<int>mnInR, mxInC;
            int row = matrix.size(), col = matrix[0].size();
            for(int i = 0;i < row;i++){
                    int mn =  1e5 + 5;
                    for(int j = 0;j < col;j++)
                            if(matrix[i][j] < mn)
                                    mn = matrix[i][j];
                    mnInR.insert(mn);
            }
            for(int i = 0;i < col;i++){
                    int mx = -1;
                    for(int j = 0;j < row;j++)
                            if(matrix[j][i] > mx)
                                    mx = matrix[j][i];
                    mxInC.insert(mx);
            }
            for(auto k : mnInR)
                    if(mxInC.count(k))
                            ans.push_back(k);
            return ans;
    }
};