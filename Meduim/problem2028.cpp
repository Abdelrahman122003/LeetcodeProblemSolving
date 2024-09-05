class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int size = rolls.size(), currSum = 0, allSize = n + size;
        for(auto k : rolls)
            currSum += k;
        int missing = (mean * allSize) - currSum;
        // missing  = 4, n = 5 ==> impossible, missing = 36, n = 5 ==> impossible to get answer
         if (missing < n || missing > 6 * n) {
            return {};
        }
        cout << missing << endl;
       vector<int>ans(n ,1);
        missing -= n;
        for(int i = 0;i < n;i++){
            int incre = min(6 - ans[i], missing);
            ans[i] += incre, missing -= incre;
            if(!missing)
                break;
        }
        return ans;
    }
};