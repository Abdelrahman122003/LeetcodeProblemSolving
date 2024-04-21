// first apporach ----> disjonint set union 
struct dsu{
        vector<int>parent, sz;
        dsu(int n){
                parent = sz = vector<int>(n+1);
                for(int i = 1;i < n;i++)
                        parent[i] = i, sz[i] = 1;
        }
        int find(int x){
                if(parent[x] == x)
                        return x;
                return parent[x] = find(parent[x]);
        }
        void uni(int x, int y){
                x = find(x);
                y = find(y);
                if(x == y)
                   return;
                if(sz[y] > sz[x])
                        swap(x, y);
                parent[y] = x; 
                sz[x] += sz[y];
        }
};


class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
           dsu d(n);
            for(auto a : edges)
                   d.uni(a[0], a[1]);
            return d.find(source) == d.find(destination);
    }
};




// second appoarch ---> dfs
// class Solution {
// public:
//     vector<vector<int>>adj;
//     set<int>s;    
//     vector<bool>vis;
//     void dfs(int n)
//     {
//             vis[n] = true;
//             s.insert(n);
//             for(auto k : adj[n])
//                     if(!vis[k])
//                             dfs(k);
//     }
//     bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
//          adj = vector<vector<int>>(n);
//          vis = vector<bool>(n);
//          for(auto k : edges)
//                  adj[k[0]].push_back(k[1]),  adj[k[1]].push_back(k[0]);
           
//           for(int i = 0; i < n;i++){
// //                to update set(contian connected component)
//                   s.clear();
//                   if(!vis[i])
//                           dfs(i);
//                   if(s.count(source) && s.count(destination))return true;
//           }
            
//             return false;
//     }
// };