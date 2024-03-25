class Solution {
public:
    string decodeString(string s) {
      stack<int>stNumber;
      stack<string>sString;
            int num = 0;
            string res = "";
            for(auto k : s){
                    if(isdigit(k))
                            num = num*10 + (k - '0');
                    
                    else if(isalpha(k))
                        res += k;
                    else if(k == '['){
                            stNumber.push(num);
                            sString.push(res);
                            num = 0;
                            res = "";
                    }
                    else{
                            int n = stNumber.top();
                            stNumber.pop();
                            string str = sString.top();
                            sString.pop();
                            while(n--)
                                    str += res;
                            
                            res = str;
                    }
            }
            return res;
    }    
};