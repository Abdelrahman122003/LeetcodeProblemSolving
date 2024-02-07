class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        bool ch = true;
        sort(nums.begin(), nums.end());
        int n = nums.size()/3;
        vector<vector<int>>v(n, vector<int>(3));
        int i = 0, j = 0, count = 0;
        while(n--){
                count = 0;
                while(count < 3)v[j][count++] = nums[i++];
                if(v[j][2] - v[j][0] > k)return {};
                j++;    
        }
        return v;
    }
};