class Solution {
public:
    string reverseParentheses(string s) {
        stack<string>st;
            string str = "";
            int i = 0;
            for(auto k : s){
                    if(isalpha(k))
                       str+=k;
                    else if(k == '(')
                            st.push(str), str = "";
                    else{
                            reverse(str.begin(), str.end());
                            string top = "";
                            top = st.top(),st.pop();
                            str = top + str;
                    }
            }
            return str;
    }
};