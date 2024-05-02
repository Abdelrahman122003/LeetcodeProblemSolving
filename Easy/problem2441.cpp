class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int mx = -1;
            set<int>s;
            for(auto k : nums)
                    if(k < 0)
                            s.insert(k);
            for(auto k : nums)
                    if(k > 0 && mx < k && s.count(-k))
                            mx = max(mx, k);
            return mx;
    }
};