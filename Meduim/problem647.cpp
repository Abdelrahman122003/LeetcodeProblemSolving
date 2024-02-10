class Solution {
public:
        
    bool chPail(string s, int i, int j){
            while(i < j){
                    if(s[i] != s[j])return false;
                    i++, j--;
            }
            return true;
    }
    int countSubstrings(string s) {
         int n = s.size();
    int count = 0;

    for(int i = 0;i < n;i++){
        for (int len = i; len < n; len++)
        {
                // if(len - i== 0)count++;
            if(chPail(s, i, len))count++;
        }

    }
    return count;
    }
};