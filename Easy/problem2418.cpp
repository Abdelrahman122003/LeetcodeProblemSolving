class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = heights.size();
            vector<pair<int, string>>all(n); 
            for(int i = 0; i < n;i++)
                    all[i] = {heights[i], names[i]};
            sort(all.rbegin(), all.rend());
        for(int i = 0; i < n;i++)
                names[i] = all[i].second;
        return names;
    }
};