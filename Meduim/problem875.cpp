class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
    ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
      // binary search answer
      // piles.length <= 1e4, piles.length <= h <= 1e9 so mx(r) = 1e9 * 1e4 = 1e13
      long long l = 1, r = 1e13+9, ans = -1;
      while(l <= r){
        long long mid = (l+r)/2;
        int sum = 0;
        for(auto p : piles){
          sum+=p / mid;
        sum+=(p % mid != 0);
        }
        if(sum <= h){
          ans = mid;
          r = mid-1;
        }else{
          l = mid+1;
        }
      }
      return ans;
    }
};