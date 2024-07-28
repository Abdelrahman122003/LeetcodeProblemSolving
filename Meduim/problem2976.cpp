// // Approach: Floyd Warshall 
// // Time Complexity: O(n + m)
// class Solution {
// public:
//     long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
//         vector<vector<long long>>dist(26, vector<long long>(26, 0x3f3f3f3f));
//            //Set the distance between a character and itself to zero           
//             for(int i = 0; i < 26;i++)
//                     dist[i][i] = 0;
//            // Fill the initial transformation costs from the given original,   
//             for(int i = 0; i < changed.size();i++)
//                     dist[original[i] - 'a'][changed[i] - 'a'] = min(dist[original[i] - 'a'][changed[i] - 'a'], (long long)cost[i]);
            
//             // Use Floyd-Warshall algorithm to find the shortest path between any two characters
//             for(int k = 0; k < 26;k++)
//                     for(int i = 0; i < 26;i++)
//                             for(int j = 0; j < 26;j++)
//                                     dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
//              // To get cost to convert source to target 
//             long long ans = 0;
//             for(int i = 0; i < source.size();i++)
//             {
//                     if(dist[source[i] - 'a'][target[i] - 'a'] >= 0x3f3f3f3f)
//                             return -1;
//                     else
//                             ans += dist[source[i] - 'a'][target[i] - 'a'];
//             }
//             return ans;
//     }
// };


#define ll long long
// Approach : Dijkstra 
// Time Complexity: O(n + m)
class Solution {
public:
    // static const ll INF = 1e18;
    vector<vector<pair<ll, ll>>>graph;
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) 
    {
         graph = vector<vector<pair<ll, ll>>>(26);               
        // build graph for use it in dijkstra
        for(int i = 0; i < original.size(); i++)
                graph[original[i] - 'a'].push_back({changed[i]-'a', (ll)cost[i]});
//      to store min distance from character to another character
        vector<vector<ll>>minDis(26, vector<ll>(26));

        // calculate shortest path from every character to all another characters
        for(int i = 0; i < 26; i++)
                minDis[i] = dijkstra(i);
        ll minCost = 0;
        for(int i = 0; i < source.size(); i++)
                {
                        if(minDis[source[i] - 'a'][target[i] - 'a'] ==  1e18)
                                return -1;
                        minCost +=  minDis[source[i] - 'a'][target[i] - 'a'];
                }
        return minCost;
    }
private:
        vector<ll> dijkstra(ll source){
                priority_queue<pair<ll, ll> , vector<pair<ll,ll>>, greater<pair<ll, ll>>>q;
                q.push({0, source});
                 vector<ll>dist(26,  1e18);
                dist[source] = 0;
                while(!q.empty()){
                        ll currChar = q.top().second;
                        ll currCost = q.top().first;
                        q.pop();
                        if(dist[currChar] < currCost)
                                continue;
                        for(auto k : graph[currChar]){
                                ll nextChar = k.first;
                                ll nextCost = k.second;
                                  // If we found a cheaper conversion, update its cost
                                if(dist[currChar] + nextCost < dist[nextChar]){
                                        dist[nextChar] = dist[currChar] + nextCost; 
                                        // Add the updated conversion to the queue for further exploration
                                        q.push({dist[nextChar], nextChar});
                                }
                        }
                }
                // Return the array of minimum conversion costs from the starting character to all others
                return dist;
        }
};