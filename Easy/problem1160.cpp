class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int>c(26);
        for(int i =0 ;i < chars.size();i++){
          c[chars[i] - 'a']++;
        }
        int ans = 0;
        for(int i =0 ;i < words.size();i++){
          vector<int>cc(26);
          for(int j =0;j < words[i].size();j++){
            cc[words[i][j] - 'a']++;
          }
          bool f = true;
          for(int j =0;j < 26;j++){
            if(c[j] < cc[j]) f = false;
          }
          if(f)ans+=words[i].size();
        }
      return ans;
    }
};