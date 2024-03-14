class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int size = nums.size();
            vector<int>prefix(size+1, 0);
            
//             freq for prefixes
        unordered_map<int, int>m;
//             prefix sum 
            for(int i  = 1; i <= size ;i++)
                    prefix[i] = prefix[i-1] + nums[i-1], m[prefix[i]]++;
            int ans = 0; 
//             let us take an example ---> 1 0 1 0 1
            
//             0 1 2 3 4 5   indies in prefix array 
//             0 1 1 2 2 3   prefixes in prefix array
//             then calculate freq
//             number    freq
//             0     ->   1
//             1     ->   2
//             2     ->   2
//             3     ->   1
//             so let us start in this iteration
            for(int i = 1;i <= size ;i++){
//                     goal=2 + prefix[i-1]=0  so all equal to 2
//                     that mean we need range with sum  = 2
//                     for example
//                    0 1 1 2 2 3
//                    prefix[3] - prefix[0] = 2  = goal same prefix[0]+2  = 2
//                     ans += prefix[all(goal + prefix[i-1]);
                    int all = goal + prefix[i-1];
                    if(m.count(all) != 0)
                            ans += m[all];
//                     why prefix[i] because i am take all before index and i
                    m[prefix[i]]--;
            }
            return ans;
    }
};