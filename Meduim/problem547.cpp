class Solution {
public:
    void dfs(int node, vector<vector<int>>& isConnected, vector<bool>&vis){
            vis[node] = true;
            for(int i = 0;i < isConnected.size();i++){
                    if(!vis[i] && isConnected[node][i]){
                            dfs(i, isConnected, vis);
                    }
                    
            }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
                int n = isConnected.size();
            vector<bool>vis(n+1);
            int connectedC = 0;
            for(int i = 0;i < n;i++){
                   if(!vis[i]){
                           connectedC++;
                    dfs(i, isConnected, vis); 
                   }
            }
       return connectedC;
    }
};