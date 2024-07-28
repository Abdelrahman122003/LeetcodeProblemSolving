// floyd warshall algorithm

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dist(n, vector<int>(n, 0x3f3f3f3f));
// Set the distance between a node and itself to zero
            for(int i = 0; i < n;i++)
                dist[i][i] = 0;
// Set the edges of this graph in a 2D matrix
            for(auto edge : edges)
                    dist[edge[0]][edge[1]] = edge[2], dist[edge[1]][edge[0]] = edge[2];;
            
// Finds shortest paths between all pairs of vertices
            for(int k = 0; k < n; k++)
                    for(int i = 0; i < n;i++)
                            for(int j = 0; j < n;j++)
                                    dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
            vector<int>nodes(n);
// for every node, count the number of vertices for which the distance between it and another vertex is less than or equal to the distance threshold.
             for(int i = 0; i < n;i++)
                     for(int j = 0; j < n;j++)
                              nodes[i] += (dist[i][j] <= distanceThreshold);
// To get the city with the smallest number of cities that are reachable through some path 
        int mn = *min_element(nodes.begin(), nodes.end());
            cout << mn << endl;
        int ans = -1;
// To get the city with the greatest ID that is equal to mn.
        for(int i = 0;i < n;i++)
                ans = (nodes[i] == mn)?i: ans;
            
        return ans;
          
    }
};