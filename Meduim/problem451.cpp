class Solution {
public:
    string frequencySort(string s) {
        map<char, int>m;
        for(auto k : s)m[k]++;
        vector<pair<int, char>>v;
        for(auto i : m)
                v.push_back({i.second, i.first});
        sort(v.rbegin(), v.rend());
            string ans = "";
        for(auto k : v){
                while(k.first--)
                        ans+=k.second;
        }
            return ans;
    }
};