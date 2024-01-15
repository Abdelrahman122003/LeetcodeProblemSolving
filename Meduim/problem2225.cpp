class Solution {
public:
    std::vector<std::vector<int>> findWinners(std::vector<std::vector<int>>& matches) {
        map<int,pair<int, int>> mm;
        for(auto i : matches){
                mm[i[0]].first++;
                 mm[i[1]].second++;
        }
        vector<vector<int>> ans(2);
        for (auto [key, value] : mm) {
            if (!value.second)
                ans[0].push_back(key);
            else if (value.second == 1)
                ans[1].push_back(key);
        }
        return ans;
    }
};