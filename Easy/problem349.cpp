class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>s, ans;
            for(auto k : nums1)
                    s.insert(k);
            for(auto k : nums2)
                    if(s.count(k) && !ans.count(k))
                            ans.insert(k);
            vector<int>v;
            for(auto l : ans)
                    v.push_back(l);
            return v;
            
    }
};