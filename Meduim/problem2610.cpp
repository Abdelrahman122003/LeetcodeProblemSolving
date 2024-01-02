class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int, int>m;
            for(int i = 0;i < nums.size();i++)
                    m[nums[i]]++;
            int mx = -1;
            for(auto e : m)mx = max(mx, e.second);
            vector<vector<int>>ans(mx);
            for(auto e : m){
                    int i = 0;
                    while(i < e.second)ans[i].push_back(e.first), i++;
            }
            return ans;
    }
        
};