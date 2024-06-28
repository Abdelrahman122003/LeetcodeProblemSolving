class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<int, int>m;
            for(auto k : roads)
                    m[k[0]]++, m[k[1]]++;
            vector<pair<int, int>>v;
            for(auto [k, vv] : m)
                    v.push_back({vv, k});
            sort(v.rbegin(), v.rend());
            int nn = n;
            for(auto [vv, k] : v)
                    m[k] = n, n--;
            long long ans = 0;
            for(auto k : roads)
                    ans += m[k[0]], ans += m[k[1]];
            return ans;
    }
};