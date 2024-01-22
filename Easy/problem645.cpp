class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>ans(2);
        vector<bool>ch(nums.size()+1);
        for(auto i : nums){
                if(ch[i])ans[0] = i;
                else ch[i] = true;}
        for(int i = 1 ; i <= nums.size();i++)
                if(!ch[i])ans[1] = i;
            
            return ans;
    }
};