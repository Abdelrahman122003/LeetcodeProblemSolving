class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int pre = 0, ans  = 0;
            for(auto i : bank){
                  int cur = 0;
                    for(auto k : i)
                            cur+=(k == '1');
                    if(pre)
                            ans += pre * cur;
                     if(cur)pre = cur;
        }
       return ans;
    }
};