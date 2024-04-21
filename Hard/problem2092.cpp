struct dsu{
        vector<int>parent, sz;
        dsu(int n){
                parent = sz = vector<int>(n);
                for(int i = 0;i < n;i++)
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
                        return ;
                if(sz[y] > sz[x])
                        swap(x, y);
                parent[y] = x;
                
                sz[x] += sz[y];
        }
        bool connected(int x, int y){
                return find(x) == find(y);
        }
        
};



class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        map<int, vector<pair<int, int>>>m;
            for(auto v : meetings)
                   m[v[2]].push_back({v[0], v[1]});
        dsu d(n);
        d.uni(0, firstPerson);
        
        for(auto v : m){
                  // Unite two persons taking part in a meeting
                for(int i = 0 ;i < v.second.size();i++){
                        d.uni(v.second[i].first , v.second[i].second);
                }
                  
            // If any one knows the secret, both will be connected to 0.
            // If no one knows the secret, then reset.
                for(int i = 0 ;i < v.second.size();i++){
                        if(!d.connected(v.second[i].first ,0))
                                d.parent[v.second[i].first] = v.second[i].first,
                                d.parent[v.second[i].second] = v.second[i].second;
                }
        }
            // Al those who are connected to 0 will know the secret
            vector<int>ans;
            // ans.push_back(0);
            for(int i = 0;i < n;i++){
                    if(d.connected(i ,0))
                            ans.push_back(i);
            }
        return ans;
            
    }
};

// 2 1 3 
//   2 3
//   1 0