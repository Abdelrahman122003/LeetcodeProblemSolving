class Solution {
public:
    int firstUniqChar(string s) {
    int in = -1;
    vector<int>v(26, 0);
    for(long long i = 0; i < s.size();i++){    
        v[s[i] - 'a']++;
    }
    for(long long i = 0; i < s.size();i++){
        if(v[s[i]-'a'] == 1){
            in = i;
            break;
        }
    }
    return in;
    }
};