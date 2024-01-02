class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        map<char, vector<int>>m;
            for(int i = 0;i < s.size();i++){
                    m[s[i]].push_back(i);
            }
       int ans = -1;
       for(auto k : m){
               if(k.second.size() >= 2){
                       int calc = k.second.back() - k.second.front()-1;
                    ans = max(ans, calc);
               }
       }
            return ans;
    }
};