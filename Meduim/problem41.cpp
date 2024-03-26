class Solution {
public:
//         first approach
    int firstMissingPositive(vector<int>& nums) {
            set<int>s;
            for(auto k : nums)
                    if(k > 0)s.insert(k);
// In all cases, the missing number must exist within the range of [1, 1e5], as the size of the array is equal to 1e5. Assuming all numbers in the array are positive and there are no duplicates, the maximum possible missing number to print is 1e5+1
            for(int i = 1; i <= 1e5+1;i++)
                    if(!s.count(i))
                            return i;
            return 0;
    }
//     second approach
    int firstMissingPositive(vector<int>& nums) {
            int n = nums.size();
            vector<bool>v(n+1, false);
            for(auto k : nums)
                    if(k > 0 && k <= n)v[k] = true;
            for(int i = 1;i <= n;i++)
                    if(!v[i])return i;
            return n+1;
    }
};
