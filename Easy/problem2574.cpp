class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int>pre(nums.size());
        vector<int>suff(nums.size()+1);
        pre[0] = 0;
        int index = 0;
        for (int i = 1; i < nums.size(); ++i)pre[i] = pre[i-1] + nums[index++];
        suff[nums.size()-1] = 0;
        index = nums.size()-1;
        for (int i = nums.size()-2; i >= 0; i--)suff[i] = suff[i+1] + nums[index--];


        for (int i = 0; i < nums.size(); ++i) {
            pre[i] = abs(pre[i] - suff[i]);
        }
        return pre;
    }
};  