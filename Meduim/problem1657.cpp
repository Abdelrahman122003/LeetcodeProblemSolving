class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int>v1(26), v2(26);
        set<char>s1,s2;
        if(word1.size() != word2.size())return false;
        for(int i = 0;i < word1.size();i++){
          v1[word1[i] - 'a']++;
          s1.insert(word1[i]);
        }
        for(int i = 0;i < word2.size();i++){
          v2[word2[i] - 'a']++;
          if(!s1.count(word2[i])){
            return false;
          }
        }
        sort(v1.begin(), v1.end());
         sort(v2.begin(), v2.end());
        for(int i = 0;i < 26;i++){
          if(v1[i]!=v2[i])return false;
        }
        return true;
    
    }
};