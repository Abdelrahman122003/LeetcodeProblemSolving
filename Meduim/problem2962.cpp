class Solution {
public:
// for example 
// array = [3, 2, 7 ,10, 2 ,10, 1 ,6, 10, 7 ,10, 10, 9 ,8, 3]  mx = 10, k = 3


// Initially, the variable r iterates until it reaches index 8. At this index, the value of mx is equal to k.
// Consequently, l = 0, r = 8.
// Therefore, if we start from indices 0, 1, or 2, the number of mxE is equal to k, resulting in the number of subarrays being equal to 3.
// Thus far, the counter is 3.
// and so on .......
    long long countSubarrays(vector<int>& nums, int k) {
        int maxE = *max_element(nums.begin(), nums.end());
            return slidingWindow(nums, k, maxE);
    }
  long long slidingWindow(vector<int>&nums, int k,int maxE){
          
            int counterM = 0, l = 0;
          long long counter = 0;
            for(int r = 0; r < nums.size();r++){
                    counterM+=(nums[r] == maxE);
                    while(counterM == k){
                         counterM-=(nums[l] == maxE);
                            l++;
                    }
                    counter += l;
            }
          return counter;
  }
};

