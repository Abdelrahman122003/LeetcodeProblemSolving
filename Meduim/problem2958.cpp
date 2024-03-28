class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l = 0, r = 0,n =  nums.size(), ans = 0;
        unordered_map<int, int>m;
         while(r < n && l <= r){
                while(r < n && m[nums[r]] < k)
                        m[nums[r++]]++;
                 ans = max(ans, r - l);
                 m[nums[l]]--;
                 l++;
         }
            return ans;
    }
};