const int N = 1e5+5;

vector<int>factors[N];
// to use it only one  =during create object of solution class 
bool done = 0;
// this function to get all fasctors of numbers expact primes
// sieve algorithm
void sieve(){
        if(done)
                return;
        vector<bool>is_prime(N+1, true);
        for(int i = 2;i < N;i++){
                if(!is_prime[i])
                        continue;
                for(int j = i;j < N;j+=i){
                        is_prime[j] = 0;
                        factors[j].push_back(i);
                }
        }
        done = 1;
}


class Solution {
public:
        vector<int>adj[N];
        vector<bool>vis;
   void dfs(int node ){
           vis[node] = true;
           for(auto l : adj[node])
                   if(!vis[l])
                           dfs(l);
   }
    bool canTraverseAllPairs(vector<int>& nums) {

            sieve();
            int n = nums.size();
            map<int, int>m;
            vis = vector<bool>(n, false);
//             to make adj matrix using prime factoriztion(array of factors) without dublicate
            for(int i = 0;i < n;i++){
                    auto v = factors[nums[i]];
                    for(int x : v){
                            if(m.find(x) == m.end())
                                 m[x] = i;
                            else {
                                    adj[i].push_back(m[x]);
                                    adj[m[x]].push_back(i);
                            }
                    }
            }
            dfs(0);
            for(auto l : vis)
                    if(!l) return false;
            return true;
    }
};

