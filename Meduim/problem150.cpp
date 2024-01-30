class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        for(auto token : tokens){
                if(token.size() > 1 || isdigit(token[0]))
                        s.push(stoi(token));
                else{
                        int x = s.top();
                        s.pop();
                        int y = s.top();
                        s.pop();
                        
                        int result = 0;
                        if(token == "+")
                                s.push(x+y);
                        else if(token == "-")
                                s.push(y-x);
                        else if(token == "*")
                                s.push(x*y);
                        else 
                                s.push(y/x);
                }
           
        }
            return s.top();
    }
};