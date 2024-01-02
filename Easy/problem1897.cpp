class Solution {
public:
    bool makeEqual(vector<string>& words) {
        map<char, int>m;
            for(int i = 0;i < words.size(); i++){
                    for(int k = 0;k < words[i].size();k++){
                            m[words[i][k]]++;
                    }
            }
            bool f = true;
            for(auto kk : m){
                    if(kk.second%words.size()){f = false;break;}
            }
            return f;
    }
};