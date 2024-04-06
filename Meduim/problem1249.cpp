class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int counter = 0;
            stack<int>st;
            vector<bool>vis(s.size(), false);
            for(int i = 0;i < s.size();i++){
                    if(s[i] == '(')st.push(i);
                    else if(s[i] == ')'){
                            if(!st.empty()){
                                    vis[i] = true;
                                    vis[st.top()] = true;
                                    st.pop();
                            }
                    }
            }
            string ans = "";
            for(int i = 0;i < s.size();i++){
                    if(!vis[i] && (s[i] == '(' or s[i] == ')'))
                     ans += ""; 
                    else ans += s[i];
            }
            return ans;
    }
};