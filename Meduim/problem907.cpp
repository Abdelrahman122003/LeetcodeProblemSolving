#define ll  long long
class Solution {
public:
    const ll mod = 1e9+7;
    // important problem + hard problem
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<ll>dp(n);
        vector<ll>st;
        ll ans = 0;
        for(ll i = 0;i < n;i++){

            while(!st.empty() && arr[st.back()] > arr[i])
                st.pop_back();

            if(st.empty())
                dp[i] = arr[i] * (i+1);
            else
                dp[i] = dp[st.back()] + (i - st.back()) * arr[i];
            dp[i]%= mod;
            ans += dp[i];
            ans %= mod;
            st.push_back(i);
        }
        return ans;
    }
};