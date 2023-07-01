class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>>m;
        for(int i = 0;i < strs.size();i++){
          string str = strs[i];
          sort(str.begin(), str.end());
          if(m[str].size() == 0){
            m[str].push_back(strs[i]);
          }else{
            m[str].push_back(strs[i]);
          }
        }
        vector<vector<string>>v;
        for(auto k : m){
          vector<string>vv;
          for(int i = 0 ;i < k.second.size();i++){
            vv.push_back(k.second[i]);
          }
          v.push_back(vv);
        }
        return v;
    }
};