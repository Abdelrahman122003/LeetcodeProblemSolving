class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        for(int i = 2;i < cost.size();i++){
                cost[i] += min(cost[i-1], cost[i-2]);
        }
         //in this we must minimize between last two num because we chioce last num or number that before last element (ont step or two step)
        return min(cost[cost.size()-2], cost[cost.size()-1]);
    }
};