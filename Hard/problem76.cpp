class Solution {
public:
string minWindow(string s, string t) {
    int ans = INT_MAX;
    map<char, int>m, reC;
    for(auto k : t)reC[k]++;
    int ansI = -1, ansJ = -1;
        int have = 0, need = reC.size();
    int i = 0;
    for (int j = 0; j < s.size(); j++) {
            char c = s[j];
            m[c]++;
            if(reC.count(c) && m[c] == reC[c])
                    have++;
            while(need == have){
                if(ans > j-i+1)
                        ansI = i, ans = j-i+1;
                m[s[i]]--;
                if(reC.count(s[i]) && m[s[i]] < reC[s[i]])have--;
                i++;
            }
    }
    return (ans == INT_MAX)?"" :s.substr(ansI, ans);
}
};