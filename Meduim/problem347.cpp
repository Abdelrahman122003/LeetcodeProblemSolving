class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int>m;
        vector<pair<int, int>>v;
        for(int i = 0; i < nums.size();i++){
          m[nums[i]]++;
        }
        // freq
        for(auto l : m){
          v.push_back({l.second, l.first});
        }
        sort(v.begin(), v.end());
        vector<int>res;
        int c = 0, in = v.size()-1;
        while(c < k){
          res.push_back(v[in].second);
          c++;
          in--;
        }
        return res;
    }
};