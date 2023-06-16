class Solution {
public:
    string removeStars(string s) {
      stack<char>st;
       for(int i = 0;i < s.size();i++){
         if(s[i] != '*')st.push(s[i]);
         else if(s[i] == '*') st.pop();
       }
       string res = "";   
       if(st.size() == 0)return res;
       while(!st.empty()){
         res += st.top();
         st.pop();
       }
       reverse(res.begin(), res.end());
       return res;
    }
};