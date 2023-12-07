class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
      std::ios_base::sync_with_stdio(false);
      std::cout.tie(nullptr);
      std::cin.tie(nullptr);
      vector<pair<long long, long long>>v;
      for(long long i = 0;i < nums1.size();i++){
        v.push_back({nums2[i], nums1[i]});
      }
      sort(v.rbegin(), v.rend());
      priority_queue<long long, vector<long long>, greater<long long>>q;
      long long sum  = 0;
      for(long long i = 0;i < k-1;i++){
        sum += v[i].second;
        q.push(v[i].second);

      }
      long long ans = 0;
      for(long long i = k-1;i < nums1.size();i++){
        ans = max(ans, (sum + v[i].second) * v[i].first);
        if(!q.empty() && q.top() < v[i].second){
          sum -= q.top();
          sum += v[i].second;
          q.pop();
          q.push(v[i].second);
        }
      }
      return ans;
    }
};