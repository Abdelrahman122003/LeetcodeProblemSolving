// First Solution: Sliding Window Solution
// class Solution {
// public:
//     int numberOfSubarrays(vector<int>& nums, int k) {
//         return abs(slidingWindow(nums, k) - slidingWindow(nums, k-1));
//     }
//    int slidingWindow(vector<int>nums, int k){
//            int n = nums.size(),counter = 0, l = 0, ans = 0;
//            for(int i = 0;i < n;i++){
//                    counter += (nums[i] % 2);
//                    while(l < n && counter > k)
//                            counter-=(nums[l]%2), l++;
//                    ans += (i - l + 1);
//            }
//            return ans;
//    }
// };

// Second Solution: Using Prefix Sum
class Solution
{
        public:
         int numberOfSubarrays(vector<int>&nums,int k){
                 int n = nums.size(), ans = 0, currSum = 0;
                 map<int, int>m;
                 for(auto &k : nums)
                         k = (k%2)?1:0;
                 m[0] = 1;
                 for(int i = 0;i <n;i++){
                         currSum += nums[i]%2;
                         if(m.find(currSum - k) != m.end())
                                 ans += m[currSum - k];
                         m[currSum]++;
                }
                 return ans;
         }
};