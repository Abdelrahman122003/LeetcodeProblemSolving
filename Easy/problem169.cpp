class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int>m;
            for(auto k : nums)m[k]++;
            int ans = -1;
            for(auto [k, v] : m)
                    if(v > nums.size()/2)ans = k;
            
            return ans;
    }
};