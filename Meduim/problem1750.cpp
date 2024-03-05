class Solution {
public:
    int minimumLength(string s) {
            int l = 0, r = s.size()-1;
            while(l < r){
                    if(s[l] != s[r])break;
                    char current = s[l];
                    l++;
                    while(l < r && s[l] == current)l++;
                    while(r >= l && s[r] == current)r--;
            }
            return  r - l +1;
    }
};