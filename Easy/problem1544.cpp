class Solution {
public:
    string makeGood(string s) {
       int n = s.size();
        deque<char>d;
        for (int i = 0; i < n; i++) {
            if(i == 0) {
                d.push_back(s[i]);
                continue;
            }
            if(((char)(d.back() + 32) == s[i] || d.back() == (char)(s[i] + 32)) && !d.empty()){
                d.pop_back();
                continue;
            }
            else
            {
                d.push_back(s[i]);
            }
        }
        string str = "";
        // cout << d.size() << endl;
        if(!d.empty()){
            for (int i = 0; i < d.size(); i++) str += d[i];
            return str;
        }
        return "";
    }
};