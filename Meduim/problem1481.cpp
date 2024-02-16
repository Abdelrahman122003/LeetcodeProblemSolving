class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int kk) {
        map<int, int >m;
            for(auto k : arr)
                    m[k]++;
            deque<pair<int, int>>v;
            for(auto [k, val] : m)
                    v.push_back({val, k});
            sort(v.begin(), v.end());
            int count = 0;
            for(auto k : v)
                    if(k.first <= kk)kk-= k.first, count++;
            return m.size() - count;
    }
};