class Solution {
public:
        
        vector<vector<int>>ans;
        vector<int>temp;
        int sum;
        int t;
        vector<int>_can;
    vector<vector<int>> combinationSum(vector<int>& can, int tar) {
            t = tar;
            sum = 0;
            _can = can;
            backtrack(0);
            return ans;
    }
        
        
        
   void backtrack(int i){
//            base case
           if(i >= _can.size() || sum > t){
                   return;
           }
            if(sum == t)
           {
                   ans.push_back(temp);
                    return;
           }
           if(sum < t){
//          peek
            sum += _can[i];
            temp.push_back(_can[i]);
            backtrack(i);
//          leave
            sum -= _can[i];
            temp.pop_back();
           }
           backtrack(i+1);
   }
};