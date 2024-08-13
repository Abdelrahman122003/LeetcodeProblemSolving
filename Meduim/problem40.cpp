class Solution {
public:
        
        vector<vector<int>>ans;
        vector<int>temp;
    vector<vector<int>> combinationSum2(vector<int>& can, int tar) {
            sort(can.begin(), can.end());
            backtrack(0, tar, can);
            return ans;
    }
   void backtrack(int i, int target, vector<int>& can){
//         get an answer
           if(!target)
                   ans.push_back(temp);
//            base case
           if(target <= 0 || i == can.size())
                   return;
//          peek
            temp.push_back(can[i]);
            backtrack(i+1, target-can[i], can);
            temp.pop_back();
// This loop avoids duplicate combinations, such as:
 // For example:
 // 0  1  2  3
 // 1, 1, 2, 7
 // 1(0), 7(3)
 // 1(1), 7(3)
// If the first one is taken, don't take the next one if this combination reaches the target.
            while(i+1 < can.size() && can[i] == can[i+1])
                    i++;
//          leave
            backtrack(i+1, target, can);
   }
};
