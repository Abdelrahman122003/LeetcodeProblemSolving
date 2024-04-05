class Solution {
public:
    string makeGood(string s) {
       int n = s.size();
            string str = "";
    for (int i = 0; i < n; i++) {
        if(!str.empty() && (abs(str.back() - s[i]) == 32) && str.back() != s[i]){
                str.pop_back();
        }else{
            str += s[i];
        }
    }
            return str;
    }
};