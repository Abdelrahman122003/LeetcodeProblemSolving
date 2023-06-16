class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int s = min(word1.size(), word2.size());
        string str = "";
        for(int i = 0;i < s;i++){
          str+=word1[i];
          str+=word2[i];
        }
        if(min(word1.size(), word2.size()) == word1.size()){
          str += word2.substr(s, word2.size());
          
        }else{
          str += word1.substr(s, word1.size());
        }
        return str;
    }
};