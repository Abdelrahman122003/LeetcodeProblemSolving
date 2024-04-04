class Solution {
public:
    int maxDepth(string str) {
            int ans = 0, counter = 0;
            for(auto k : str)
                    if(k == '(')counter++, ans = max(counter, ans);
                    else if(k == ')')  counter--;
            return ans;
    }
};