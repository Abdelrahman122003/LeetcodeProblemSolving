class Solution {
public:
    int maxScore(string s) {
      int count = 0; 
      if(s.size() == 2){
        if(s[0] == '0')count++;
        if(s[1] == '1')count++;
        return count;
      }
      int mx = 0;
      for(int i = 1;i < s.size();i++){
        int o = 0, z = 0;
        for(int j = 0;j < i;j++)
          if(s[j] == '0')z++;
        for(int j = i;j < s.size();j++)
          if(s[j] == '1')o++;
        mx = max(mx, o+z);
      }
      return mx;
    }
};