class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double, int>>v;
            for(int i = 0 ; i < wage.size();i++){
                    v.push_back({(double)wage[i] / quality[i], quality[i]});
            }
            // sort ratio(wage / quality) in asc order
            sort(v.begin(), v.end());
            priority_queue<int>q;
            double cost = numeric_limits<double>::max(), totalQ = 0;
            for(int i = 0 ; i < wage.size();i++){
                    q.push(v[i].second);
                    totalQ += v[i].second;
                // If we have more than k workers,
                // remove the one with the highest quality
                    if(q.size() > k)
                         totalQ -= q.top(), q.pop();
                // If we have exactly k workers,
                // calculate the total cost and update if it's the minimum
                    if(k == q.size())
                            cost = min(cost, totalQ * v[i].first);
            }
            return cost;
    }
};