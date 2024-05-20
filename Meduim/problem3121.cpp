class Solution {
public:
    int numberOfSpecialChars(string word) {
       int count = 0;
       vector<int>l(26, -1), u(26, -1);
        for(int i = 0;i < word.size();i++){
          char k = word[i];
          char c = tolower(k);
          if(islower(k))
            l[k- 'a'] = i;
          if(isupper(k) && u[k-'A'] == -1)
           u[k- 'A'] = i;
        }
       for(int i  = 0;i < 26;i++)
         count+= (l[i] != -1 && u[i] != -1 && l[i] < u[i]);
        return count;
    }
};