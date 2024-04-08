class Solution {
public:
    bool checkValidString(string s) {
            stack<int>openB, ast;
            for(int i = 0;i < s.size();i++){
                    if(s[i] == '(')openB.push(i);
                    else if(s[i] == '*')ast.push(i);
                    else{
                            if(!openB.empty())
                                    openB.pop();
                            else if(!ast.empty())
                                    ast.pop();
                            else 
                                    return false;
                    }
            }
           while(!openB.empty() && !ast.empty()){
                   if(openB.top() > ast.top())
                           break;        
                openB.pop(), ast.pop();
           }
            return openB.empty();
    }
};