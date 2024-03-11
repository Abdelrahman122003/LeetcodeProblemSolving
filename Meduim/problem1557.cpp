class Solution {
public:
    static const int N = 1e5+4;
    vector<int>adj[N];
    vector<int>ans;
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        for(auto k : edges)
                adj[k[1]].push_back(k[0]);
       for(int i = 0;i < n;i++)
               if(adj[i].empty())
                       ans.push_back(i);
            return ans;
    }
};