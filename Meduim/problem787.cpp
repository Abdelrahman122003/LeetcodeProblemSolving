 class Solution {
public:
        const int INF = INT_MAX;
        vector<vector<pair<int, int>>>adj;
        vector<int>dist;
        vector<int>stops;
        int dijkstra(int s, int d, int k){ 
          priority_queue<tuple<int, int ,int>, vector<tuple<int , int , int>>, greater<tuple<int, int ,int>>>q;
                q.push({0, s, 0});
                dist[s] = 0;
                while(!q.empty()){
                        auto [dis, v, stop] = q.top();
                        // int v = q.top().second.first;
                        // int dis = q.top().first;
                        // int stop = q.top().second.second;
                        q.pop();
                        if(d == v)
                                return dis;
// When we reach the last point, the stop count increases by one, but the last point itself should not be considered as a stop.
                        if(stop == k+1)
                                continue;
                        for(auto [node, disN] : adj[v])
                        {
                                int nextD = disN + dis;
                                int nextS = stop+1;
                                if(dist[node] > nextD || stops[node] > nextS){
                                        dist[node] = nextD;
                                        stops[node] = nextS;
                                        q.push({dist[node],node, nextS});
                                }
                        }
                }
                
                return -1;
        }
                
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
// In this problem, the difference lies in comparing not only the distance but also the number of stops.
            adj = vector<vector<pair<int, int>>>(n);
            dist = vector<int>(n, INF);
            stops = vector<int>(n, INF);
            for(auto v : flights){
                    adj[v[0]].push_back({v[1], v[2]});
            }
            
            return dijkstra(src, dst, k);
    }
};