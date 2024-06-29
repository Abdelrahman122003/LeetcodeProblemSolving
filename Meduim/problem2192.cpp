class Solution {
public:
        static const int N = 1010;
        vector<int>adj[N];
         set<int>ans[N];
        void dfs(int ancestor, int node){
                
                ans[node].insert(ancestor);
                for(auto k : adj[ancestor])
                         // Prevent cycles
                        if(ans[node].find(k) == ans[node].end())
                                dfs(k, node);
        }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
            for(auto k : edges)
                    adj[k[1]].push_back(k[0]);
            for(int i = 0; i < n;i++)
            {
// During the DFS call, k represents the ancestor from which I will perform DFS to gather all ancestors, and i represents the node that will collect all these ancestors.
                    for(auto k : adj[i])
                           dfs(k, i);
                            
            }
             vector<vector<int>>ansV(n);
            for(int i = 0; i < n;i++)
                ansV[i] = vector<int>(ans[i].begin(), ans[i].end());
            return ansV;
            
    }
};