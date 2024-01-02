class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int>xAxis;
        for(auto k : points){
          xAxis.push_back(k[0]);
        }
        sort(xAxis.begin(), xAxis.end());
        int ans = 0;
        for(int i =0;i < points.size()-1;i++)
          ans = max(xAxis[i+1] - xAxis[i], ans);
      return ans;
    }
};