#include <vector>
using namespace std;
struct DSU {
    vector<int> parent, size;
        int comp;
    DSU(int n) {
            comp = n;
        parent = vector<int>(n + 1);
        size = vector<int>(n+1);
        for (int i = 1; i <= n; i++)
            parent[i] = i, size[i] = 1;
    }
    int uni(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)
                return 0;
        if (size[y] > size[x])
            swap(x, y);
        parent[y] = x;
        size[x] += size[y];
            comp--;
            return 1;
    }
    int find(int n) {
        if (parent[n] == n)
            return n;
        return parent[n] = find(parent[n]);
    }
        int isConnected(){
                return comp == 1;
        }
};



class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
// We will create two instances: one for Alice and one for Bob.
            DSU alice(n), bob(n);
            int count = 0;
// First, we are interested in uniting edges of type 3.
            for(auto k : edges)
// If unite returns true, it means the union was successful.
// Otherwise, it means this edge was already connected before.

                    if(k[0] == 3)
                            count += (alice.uni(k[1], k[2]) | bob.uni(k[1], k[2]));
// Then, if the edge does not already exist, unite it.
            for(auto k : edges)
            {
                    if(k[0] == 1)
                             count += alice.uni(k[1], k[2]);
                    if(k[0] == 2)
                             count += bob.uni(k[1], k[2]);
            }
            if(alice.isConnected() && bob.isConnected())
                                      return edges.size() - count;
           return -1;
    }
};