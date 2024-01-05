class Solution {
public:
        int counter;
        void dfs(int node , int parent, vector<vector<pair<int, int>>>&adj){
            for(auto [e, s] : adj[node]){
                    if(parent != e){
                        counter+=s; dfs(e, node, adj);}
                
            }
          
    }
    int minReorder(int n, vector<vector<int>>& connections) {
             vector<vector<pair<int, int>>>adj(n);
        counter = 0;
        for(int i = 0;i < n-1;i++){
                adj[connections[i][0]].push_back({connections[i][1], 1});
                adj[connections[i][1]].push_back({connections[i][0], 0});
        }
        dfs(0, -1, adj);
        return counter;
    }
};