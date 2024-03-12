class Solution {
public:
    bool isUni(string str){
           unordered_set<char>s;
            for(auto k : str){
                    if(!s.count(k))
                            s.insert(k);
                    else
                            return false;
            }
            return true;
    }
    int allCombination_backtrack(vector<string>&arr, int i, string s){
            if(!isUni(s))return 0;
            
            int ans = (int)s.size();
           for(int j = i;j < arr.size();j++)
                    ans = max(ans, allCombination_backtrack(arr, j+1, s+arr[j]));
            return ans;
    }
    int maxLength(vector<string>& arr) {
        return allCombination_backtrack(arr, 0, "");
    }
};