class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int index = -1;
        vector<int>pre(nums.size());
        pre[0] = nums[0];
        for(int i = 1;i < nums.size();i++)pre[i] = nums[i] + pre[i-1];
        int i = 0;
        while(i < nums.size()){
            if(pre[i] - nums[i] == pre[nums.size()-1] - pre[i]){
                index = i;
                break;
            }
            i++;
        }
        return index;
    }
};