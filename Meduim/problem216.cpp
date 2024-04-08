class Solution {
public:
        vector<int>nums;
        int _n, _k;
        vector<vector<int>>ans;
        vector<int>temp;
    vector<vector<int>> combinationSum3(int k, int n) {
            for(int i = 1;i <= 9;i++)
                nums.push_back(i);
            _n = n, _k = k; 
            backtrack(0);
            
            return ans;
    }
   
    void backtrack(int i){
//          base case 
            if(i > 9)
                    return;
            if(!_k)
            {
                    if(!_n)ans.push_back(temp); 
                    return;
            }
//           peek
            if(_n - nums[i] >= 0){
                    _k--;
                    _n-=nums[i];
                    temp.push_back(nums[i]);
                    backtrack(i+1);
                    _k++;
                    _n += nums[i];
                    temp.pop_back();
            }
//             leave
            backtrack(i+1);
            
    }
};