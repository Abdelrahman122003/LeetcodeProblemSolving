// disjoint sets union
struct dsu{
        vector<int> parent;
        dsu(){
                parent = vector<int>(26);
                for(int i = 0;i < 26;i++)
                        parent[i] = i;
        }
//         to find parent(smallest char in set)
        int getParent(int x){
                if(x == parent[x])
                        return x;
                return parent[x] = getParent(parent[x]);
        }
//         to uni between two sets 
        void uni(int x, int y){
                x = getParent(x);
                y = getParent(y);
                
//                 if x, y has same parent(same set)
                if(x == y)
                        return;
//              Choose the smallest parent of the set to be the parent of another set
                if(x < y)
                        parent[y] = parent[x];
                else 
                        parent[x] = parent[y];
                
        }
        
};
class Solution {
public:
    
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        dsu d;
            for(int i = 0;i < s1.size();i++)
                    d.uni((int)(s1[i] - 'a'), (int)(s2[i] - 'a'));
            for(auto &k : baseStr)
                    k = (char)(d.getParent(k-'a')+'a');
            return baseStr;
    }
};