#include <iostream>
#include <vector>
#include <algorithm>
#define ll  long long
#define all(x) x.begin(), x.end()
using namespace std;
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(all(pairs));
        ll size = pairs.size(), mx = 1;
        vector<ll>dp(size, 1);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < i; ++j) {
                if(pairs[j][1] < pairs[i][0] && dp[j]+1 > dp[i])
                    dp[i]++;
                mx = max(mx, dp[i]);
            }
        }
        return mx;
    }
};