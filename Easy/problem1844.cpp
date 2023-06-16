class Solution {
public:
    string replaceDigits(string s) {
        string str = "";
       for(int i = 0;i < s.size();i++){
            {
                if(!i&1){str += s[i];continue;}
                if(isdigit(s[i]))str += (s[i-1] + (s[i] - '0'));
                else str += s[i];
            }
        }
        return str;
    }
};