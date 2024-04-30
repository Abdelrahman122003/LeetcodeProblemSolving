class Solution {
public:
        
        unordered_map<string, vector<pair<string, double>>>graph;
        double dfs(string node,string dest, unordered_map<string, bool>&vis)
        {
                if(!graph.count(node))
                        return -1;
                vis[node] = true;
                if(node == dest)
                        return 1;
                for(auto k : graph[node]){
                        if(!vis[k.first]){
                                double p =  dfs(k.first, dest, vis);
                                if(p != -1)
                                        return p * k.second;
                        }
                }
                return -1;
        }
    vector<double> calcEquation(vector<vector<string>>& e, vector<double>&              values, vector<vector<string>>& queries)
    {
            for(int i = 0; i < e.size();i++){
                    graph[e[i][0]].push_back({e[i][1], values[i]});
                    graph[e[i][1]].push_back({e[i][0], 1/values[i]});
            }

            vector<double>ans;
            for(auto q : queries){
                 unordered_map<string, bool>vis;
                    double val = dfs(q[0], q[1], vis);
                 ans.push_back(val);
            }
            
            return ans;
    }
};