// greedy problem
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
            // nums = [1,5,10], n = 20
            long long miss = 1, counter = 0, i = 0;
            while(miss <= n){
                    if(i < nums.size() && nums[i] <= miss)
                            miss += nums[i], i++;
                    else
                            miss += miss, counter++;  
            }
            return counter;
    }
};