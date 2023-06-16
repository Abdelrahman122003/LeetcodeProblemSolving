class Solution {
public:
    string reverseWords(string s) {
       vector<string>v;
        int in = 0;
        string str = "" ,res = "";
        for(int i = 0;i < s.size();i++){
          if(s[i] != ' '){
            str += s[i];
          }else{
            if(str != "")v.push_back(str);
            str = "";
          }
        }
      if(str != ""){
          v.push_back(str);
      }
      for(int i = v.size()-1;i >= 0;i--){
          if(i == 0)res += (v[i]);
          else res += (v[i] + " ");
      }
      return res;
    }
};