class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
         map<int , string>m{{1, "Gold Medal"},{2, "Silver Medal"}, {3, "Bronze Medal"}};
            int n = score.size();
            vector<pair<int, int>>v;
            for(int i = 0;i < n;i++)
                    v.push_back({score[i], i});
            sort(v.rbegin(), v.rend());
            vector<string>ans(n);
            for(int i = 1;i <= n;i++){
                    if(m.count(i))
                            ans[v[i-1].second] = m[i];
                    else 
                             ans[v[i-1].second] = to_string(i);
            }
            return ans;
    }
};