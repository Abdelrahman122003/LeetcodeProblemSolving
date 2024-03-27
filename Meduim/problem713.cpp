class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l = 0, counter = 0;
            int n = nums.size();
            if (k <= 1) return 0;
            int p = 1;
            for(int i = 0;i < n;i++){
                    p*= nums[i];
                    while(p >= k)
                            p/=nums[l++];
                    counter+= i - l+1;
            }
            return counter;
    }
};
