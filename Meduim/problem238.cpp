class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sz = nums.size();
    vector<int>pre(sz), suff(sz), res(sz);
    pre[0] = nums[0];
    suff[sz-1] = nums[sz-1];
    for(int i = 1;i < sz;i++) pre[i] = nums[i] * pre[i-1];
    for(int i = sz-2;i >= 0;i--) suff[i] = nums[i] * suff[i+1];
    for(int i = 0;i < sz;i++){
        if(i == 0) {
            res[i] = suff[1];
            continue;
        }
        if(i == sz-1) {
            res[i] = pre[sz - 2];
            continue;
        }
        else{
            res[i] = (suff[i+1] * pre[i-1]);
        }
    }
        return res;
      }
};