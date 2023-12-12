class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);                 
    cout.tie(nullptr);
        vector<int>res(spells.size(), 0);
      sort(potions.begin(), potions.end());
      int ans = -1;
      for (int i = 0; i < spells.size(); ++i) {
          int l = 0, r = potions.size()-1;
          ans = -1;
          while(l <= r){
              int mid = (l+r)/2;
              if((long long)potions[mid] * spells[i] >= success){
                  ans = mid;
                  r = mid-1;
              }else{
                  l = mid+1;
              }
          }
          if(ans != -1)res[i] = potions.size() - ans;
      }
      return res;
    }
};