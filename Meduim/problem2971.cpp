class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long sum = nums[0] + nums[1], sumAns = -1;
        int vI = -1;
         for(int i = 2;i < nums.size();i++){
                 if(nums[i] < sum)sumAns= sum + nums[i], sum += nums[i];
                 else sum+=nums[i];
                }
          
        return sumAns;
                 
    }
};