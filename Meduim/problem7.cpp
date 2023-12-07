class Solution {
public:
    int reverse(int x) {
        bool neg = false;
        if(x < 0)neg = 1;
        x = abs(x);
        string str = to_string(x);
        std::reverse(str.begin(), str.end());
        long long res = stoll(str); 
        if(res > INT_MAX || res < INT_MIN)return 0;
        if(neg){
          res *=-1;
        }
        return res;
    }
};