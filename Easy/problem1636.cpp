class Solution {
public:
    static bool compare(pair<int, int>a, pair<int, int>b){
            if(a.first < b.first)
                    return true;
            if(a.first == b.first && a.second > b.second)
                    return true;
            return false;
    }
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int>m;
            for(auto k : nums)
                    m[k]++;
            vector<pair<int, int>>freq;
            for(auto [k, v] : m)
                    freq.push_back({v, k});
            sort(freq.begin(), freq.end(), compare);
            int i = 0;
            for(auto [v, k] : freq)
                    while(v--)
                            nums[i++] = k;
            return nums;
    }
};