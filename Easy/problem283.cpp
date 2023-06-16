class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int n = nums.size();
        int l = 0, r = 1;
         while(r < n && l < n){
        if(nums[l] == 0 && nums[r] != 0){
            swap(nums[l], nums[r]);
            l++;r++;
        }
        while(r < n){
            if(nums[r] != 0)break;
            r++;
        }
        while(l < n){
            if(nums[l] == 0)break;
            l++;
        }
        if(r <= l)r = l+1;
    }
    }
};