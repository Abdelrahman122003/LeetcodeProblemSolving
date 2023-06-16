class Solution {
public:
    int maxVowels(string s, int k) {
        map<char, bool>m{{'a', 1},{ 'e', 1}, {'i',1},{'o', 1}, {'u', 1}};
        int l = 0, r = 0, count = 0, res = 0, v = 0;
        while(r < s.size()){
          while(count < k){
            if(m[s[r]])v++;
            r++;
           count++;
          }
          if(count == k){
            res = max(res, v);
          }
          if(m[s[l]])v--;
          count--;
          l++;
        }
        return res;
    }
};