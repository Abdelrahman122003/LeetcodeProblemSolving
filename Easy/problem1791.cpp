class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int>m;
            for(auto k : edges)
                    m[k[0]]++, m[k[1]]++;
            for(auto [k , v] : m)
                    if(v == m.size()-1) 
                            return k;
            return 0;
    }
};