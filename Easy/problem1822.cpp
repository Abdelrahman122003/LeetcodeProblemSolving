class Solution {
public:
    int arraySign(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int nNeg = 0;
        for(int i = 0;i < nums.size();i++){
            if(nums[i]  == 0)return 0;
            if(nums[i] < 0)nNeg++;
        } 
        if(nNeg%2)return -1;
        return 1;
    }
};