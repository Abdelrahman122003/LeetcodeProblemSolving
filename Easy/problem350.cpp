class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<pair<int, int>>nums(1001, pair<int, int>{0, 0});
            for(auto k : nums1)
                    nums[k].first++;
             for(auto k : nums2)
                    nums[k].second++;
            nums1.clear();
            for(int k = 0; k < 1001;k++)
                    for(int i = 0; i < min(nums[k].first, nums[k].second);i++)
                            nums1.push_back(k);
            return nums1;
    }
};