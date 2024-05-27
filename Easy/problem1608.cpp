class Solution {
public:
    int specialArray(vector<int>& nums) {
            vector<int>m(1001, 0);
            for(auto k : nums)
                    m[k]++;
            int count = 0, n = nums.size();
            for(int i = 0; i <= 1000;i++){
                    if(n - count == i)
                          return i;
                    count += m[i];
            }
            return -1;
    }
};