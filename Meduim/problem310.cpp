class Solution {
public:
// Observably, the number of nodes that can be a root is equal to 2 for minimizing the height.
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
            if(n==1)return {0};
        vector<int>adj[n];
// deg --> The number of nodes directly connected to each node
            vector<int>deg(n);
            for(auto v: edges)
            {
                    adj[v[0]].push_back(v[1]);
                    adj[v[1]].push_back(v[0]);
                    deg[v[1]]++, deg[v[0]]++;
            }
            queue<int>q;
            // start travere from leaf(deg equal to 1) nodes ---> toplogicalsort
            for(int i = 0; i < n; i++)
                    if(deg[i] == 1)
                            q.push(i);
            int remainingNodes = n; 
            while(remainingNodes > 2){
                    int leafs = q.size();
                    remainingNodes -= leafs;
                    while(leafs--)
                    {
                            int top = q.front();
                            q.pop();
                            for(auto k : adj[top]){
//                                    if node has only one edge push it in queue 
                                    if(--deg[k] == 1)
                                            q.push(k);
                            }
                }
            }
            vector<int>ans;
            while(!q.empty()){
                    ans.push_back(q.front());
                    q.pop();
            }
            return ans;
    }
};
