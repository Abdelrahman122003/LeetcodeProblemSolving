class Solution {
public:
    vector<int> evenOddBit(int n) {
        vector<int>v(2);
        int count = 0;
        while(n){
            if(n&1){
                if(count%2){
                    v[1]++;
                }else{
                    v[0]++;
                }
            }
            n>>=1;
            count++;
        }
        return v;
    }
};
// 10001
// 101
// 100
