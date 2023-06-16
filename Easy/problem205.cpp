class Solution {
public:
    bool isIsomorphic(string s, string t) {
       if(t.size() != s.size())return false;
    map<char, vector<int>>m, m1;
    for (int i = 0; i < s.size(); ++i) {
        m[s[i]].push_back(i);
        m1[t[i]].push_back(i);
    }

   bool f = true, f1 = true;
    for(auto k : m){
        char c = t[k.second[0]];
        for (int i = 1; i < k.second.size(); ++i) {
            if(t[k.second[i]]!= c){
                f = false;
                break;
            }
        }
        if(!f){
            return false;
        }
    }
    for(auto k : m1){
        char c = s[k.second[0]];
        for (int i = 1; i < k.second.size(); ++i) {
            if(s[k.second[i]]!= c){
                f1 = false;
                break;
            }
        }
        if(!f1){
                return false;
        }
    }
    if(f && f1){
        return true;

    }else{
        return false;
    }
    }
};