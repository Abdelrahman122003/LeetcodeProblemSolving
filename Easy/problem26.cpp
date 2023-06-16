class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int, int>m;
        int j = 0;
        for(int i = 0; i < nums.size();i++){
          if(m[nums[i]] == 0){
            m[nums[i]]++;
            nums[j++] = nums[i];
          }
        }
        return j;
    }
};