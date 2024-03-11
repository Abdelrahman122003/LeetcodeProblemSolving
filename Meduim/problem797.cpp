class Solution {
public:
    int const N = 16;
    vector<vector<int>>paths;
    vector<int>v;
    void dfs(int n, int node, vector<vector<int>>& graph, vector<bool>&vis){
            if(v.empty())v.push_back(node);
            if(node == n){paths.push_back(v);return;}
            for(auto  k : graph[node]){
                    if(!vis[k]){
//                     peek
                  v.push_back(k);
                    vis[k] = true;
                    dfs(n, k, graph, vis);
                    vis[k] = false;
//                     pop
                   v.pop_back();
                    }
            }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
          vector<bool>vis(N, false);
            dfs(graph.size()-1, 0, graph, vis);
            
            return paths;
    }
};