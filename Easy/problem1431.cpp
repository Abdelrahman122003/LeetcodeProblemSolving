class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
       int mx = -1;
        for (int i = 0; i < candies.size(); ++i) {
            mx = max(candies[i], mx);
        }
        vector<bool>res;
        for(int i = 0;i < candies.size();i++){
            if((candies[i]  + extraCandies) >= mx) { res.push_back(true);
                continue;}
            else res.push_back(false);
        }
      return res;
    }
};