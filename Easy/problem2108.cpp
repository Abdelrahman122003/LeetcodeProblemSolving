class Solution {
public:
        
        bool ch(string str){
                int i = 0, j = str.size()-1;
                while(i < j){
                        if(str[i] != str[j])return false;
                        i++, j--;
                }
                return true;
        }
    string firstPalindrome(vector<string>& words) {
            string ans = "";
        for(auto k : words)
                if(ch(k)){ans = k;break;}
        return ans;
    }
};