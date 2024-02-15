class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
            int size = nums.size();
        vector<int>pos, neg, ans(size);
            for(auto k : nums){
                    if(k < 0)neg.push_back(k);
                    else pos.push_back(k);
            }
            int half  = size/2;
            int k = 0;
            int i = 0, j = 0;
            while(half--)
                    ans[k++] = pos[i++], ans[k++] = neg[j++];
            return ans;
            
    }
};