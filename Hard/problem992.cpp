class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
            // After calculating the total count of subarrays with distinct integers less than or equal to k using slidingWindowAtMost(nums, k), we need to isolate the subarrays that strictly meet the target k.

// This can be achieved by subtracting the total count of subarrays with distinct integers less than k (slidingWindowAtMost(nums, k - 1)) from the total count obtained earlier. By subtracting the latter from the former, we essentially remove the subarrays that don't reach k and are left with only the subarrays that have exactly k distinct integers.
        return slidingWindowCountAtMost(nums, k) - slidingWindowCountAtMost(nums, k-1);
    }
    int slidingWindowCountAtMost(vector<int>&nums, int k){
              int l = 0, counter = 0;
            map<int, int>m;
            for(int r = 0 ;r < nums.size();r++){
                    m[nums[r]]++;
                    while(m.size() > k)
                    {
                            m[nums[l]]--;
                            if(m[nums[l]] == 0) m.erase(nums[l]);
                            l++;
                    }
                    counter += (r - l +1);
            }
            return counter;
    }
};