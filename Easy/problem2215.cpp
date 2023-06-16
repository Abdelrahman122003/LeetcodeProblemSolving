class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int>s1,s2;
        for(int i = 0;i < nums1.size();i++)s1.insert(nums1[i]);
        for(int i = 0;i < nums2.size();i++)s2.insert(nums2[i]);
        vector<vector<int>>v(2);
        // Displaying set elements
        for (auto itr = s1.begin();itr != s1.end(); itr++)
        {
            if(s2.count(*itr) == 0)v[0].push_back(*itr);
        }
        for (auto  itr = s2.begin();itr != s2.end(); itr++)
        {
            if(s1.count(*itr) == 0)v[1].push_back(*itr);
        }
        return v;
    }
};