class Solution {
public:
    int compress(vector<char>& chars) {
      int n = chars.size();
      int index = 0;
      int i = 0;
       while(i < n){
         int j = i+1;
         while(j < n && chars[i] == chars[j])j++;
         chars[index++] = chars[i];
         int count = j - i;
         if(count > 1){
           string str = to_string(count);
           for(auto k : str){
             chars[index++] = k;
           }
         }
         i = j;
       }
       return index;
    }
};