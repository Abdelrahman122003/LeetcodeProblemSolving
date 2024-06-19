class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {     
            int n = profit.size();
            vector<pair<int, int>>v(n);
            for(int i = 0; i < profit.size();i++)
                    v[i] = {difficulty[i], profit[i]};
            sort(v.begin(), v.end());
            sort(worker.begin(), worker.end());
            priority_queue<int>q;
            int i = 0, maxProfit = 0;
            for(auto k : worker){
                    while(i < n && v[i].first <= k)
                            q.push(v[i++].second);
                    if(!q.empty())
                            maxProfit += q.top();
            }
            return maxProfit;
    }
};