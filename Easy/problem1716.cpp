class Solution {
public:
    int totalMoney(int n) {
      int totalM = 0;
    int count  = 0, i = 1, ans = 0;
    while(n > 0){
        int calc = 0;
        if(n > 7)
            n-=7, calc = ((i+6)*(i+7)/2) - (i-1)*(i)/2;
        else{
            calc = (n+i-1)*(n+i)/2 - (i-1)*(i)/2;
            n = 0;
        }
        ans += calc;
        i++;
    }
    return ans;
    }
};