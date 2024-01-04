class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int, int>m;
            for(auto k : nums)
                    m[k]++;
        bool ans = true;
            int anss = 0;
            for(auto kk : m)
            {
                  if(kk.second==1)
                          ans = false;
                  anss+=(kk.second/3);
                   if(kk.second%3)anss++;
            }
         if(ans)return anss;
         return -1;
    }
};