class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        long n = nums.size();
        long l = 0, r = 0, count = 0, ans = 0;
        while(l < n && r < n){
            while((count < k || (count == k && nums[r])) && (r < n)) {         
              count += (nums[r]) ? 0 : 1, r++;
            }
            ans = max(ans, r - l);
            count -= (nums[l])?0:1;
            l++;
        }
        return ans;
    }
};