
//         solution 1 --> backtrack
class Solution {
public:
        vector<vector<int>>ans;
        vector<int>v, _nums;
        int n;
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
            _nums = nums;
            backtrack(0);
            return ans;
    }
   void backtrack(int i){
           if(i == n){
                ans.push_back(v);
                   return;
           }
//            peek
        v.push_back(_nums[i]);
        backtrack(i+1);
//            leave
        v.pop_back();
//     go to this index without take it
        backtrack(i+1);
   }
};
// Solution 2 ---> bitmask
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
            set<vector<int>>s;
            vector<vector<int>>ans;
            for(int i = 0; i < (1<<n);i++){
                    vector<int>v;
                    for(int j = 0; j < n;j++){
                            if(i & (1<<j))
                                 v.push_back(nums[j]);   
                    }
                    if(!s.count(v))
                            s.insert(v), ans.push_back(v);
            }
            return ans;
    }
};
