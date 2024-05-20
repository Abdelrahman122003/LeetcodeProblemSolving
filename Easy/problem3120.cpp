class Solution {
public:
    int numberOfSpecialChars(string word) {
       int count = 0;
       cout << islower('A') << endl;
       map<int, pair<int, int>>m;
        for(auto k : word){
        char c = tolower(k);
        m[c].first+=(islower(k));
        m[c].second+=(isupper(k));
        }
        for(auto [a, k] : m)
           count+= (k.first && k.second);
        return count;
    }
};