class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        long n = nums.size();
        long l = 0, r = 0, count = 0, ans = 0;
        while(l < n && r < n){
            while((r < n) && (count < 1 || (count == 1 && nums[r]))) {         
              count += (nums[r]) ? 0 : 1, r++;
            }
            ans = max(ans, r - l - 1);
            count -= (nums[l])?0:1;
            l++;
        }
        return ans;
    }
};