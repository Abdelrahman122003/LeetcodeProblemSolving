class Solution {
public:
        vector<vector<string>>res;
        int n;
        vector<string>path;
        string in;
        bool checkPil(string str){
            int l = 0, r = str.size()-1;
            while(l < r){
                if(str[l] != str[r]){
                    return false;
                }
                l++,r--;
           }
    return true;
}
    vector<vector<string>> partition(string s) {       
       n = s.size();
            in = s;
            backtrack(0);
            return res;
    }
        void backtrack(int i){
                if(i == n){
                
                    res.push_back(path);      
                        return;
                }
                
                for(int j = i+1;j <= n;j++){
                        string cut = in.substr(i, j - i);
                        if(checkPil(cut)){
//                                 peek
                                path.push_back(cut);
                                   // Recur to find other partitions
                                backtrack(j);
//                                 leave
                                path.pop_back();
                        }
                }
        }
};