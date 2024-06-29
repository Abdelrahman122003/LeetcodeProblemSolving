class Solution {
public:

    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int minIn = -1, maxIn = -1, l = 0, r = 0, n = nums.size();
            long long ans = 0;
            for(;r < n;r++){
                    if(nums[r] > maxK || nums[r] < minK)
                            l = r+1, minIn = maxIn = -1;
                    else{
                        if(nums[r] == minK)
                                minIn = r;
                        if(nums[r] == maxK)
                                maxIn = r;
                        if(~minIn && ~maxIn)
                                ans += min(minIn, maxIn) - l + 1;
                    }
            }
            return ans;
            
    }
};

// simulation  for this example:
// [1,3,5,2,7,5], minK = 1, maxK = 5
//  iteration
//     1    =>  Take 1, which is equal to minK, so set minIn to 0.
//     2    =>  Take 3, which is not equal to minK or maxK, so nothing happens.
//     3    =>  Take 5, which is equal to maxK, so set maxIn to 2. In this case, since minIn and maxIn are not equal to -1, we calculate the value for our answer: ans = min(0, 2) - l + 1 = 1.
//     4    =>  Take 2. In this case, we calculate the value for our answer: ans = min(0, 2) - l + 1 = 1.
//     5    => Reset l to r + 1 because this range does not meet our condition, and reset the values of minIn and maxIn to -1.