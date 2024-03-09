class Solution {
public:
// first solution
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        set<int>s;
        for(auto k : nums1)
                s.insert(k);
       long long mn = 1e9+3;
       for(auto k : nums2)
               if(s.count(k))
                       mn = min(mn, (long long)k);
        return (mn==1e9+3)?-1:mn;
    }
};

// second solution
// int getCommon(vector<int>& nums1, vector<int>& nums2) {
//  int l = 0, l2 = 0;
//  while(l2 < nums2.size() && l < nums1.size()){
//          if(nums1[l] == nums2[l2])return nums1[l];
//          if(nums1[l] < nums2[l2])l++;
//          else l2++;
//  }
//  return -1;
// }

