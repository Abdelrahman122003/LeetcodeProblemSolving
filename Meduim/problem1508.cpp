class Solution {
public:
        static const int MOD = 1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>sums{0};
            int size = n * (n + 1)/2;
            for(int i = 0;i < n; i++){
                    int sum = 0;
                    for(int j = i;j < n; j++)
                            sum += nums[j], sums.push_back(sum);
            }
            sort(sums.begin(), sums.end());
            int ans = 0;
            for(int i = left; i <= right ;i++)
                     ans = (ans + sums[i]) % MOD;
            return ans;
    }
};