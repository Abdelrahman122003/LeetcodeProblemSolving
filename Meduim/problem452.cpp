class Solution {
public:

    int findMinArrowShots(vector<vector<int>>& p) {
        sort(p.begin(), p.end());
            int counter = 1;
            int x = p[0][1];
        for(int i = 1;i < p.size();i++){
                if(x < p[i][0]) x = p[i][1], counter++;
                else x = min(p[i][1], x);
        }
            return counter;
    }
        
};