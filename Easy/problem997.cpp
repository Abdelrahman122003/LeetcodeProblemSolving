class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
            if(n==1)return 1;
        unordered_map<int , pair<int, int>>m;
            for(auto k : trust)
                    m[k[0]].first++, m[k[1]].second++;
            int count = 0, ans = -1;
            for(auto [a,freq] : m)
                    if(freq.second == n-1 && !freq.first)ans = a;
            return ans;
    }
};